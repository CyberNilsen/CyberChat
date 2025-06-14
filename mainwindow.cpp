#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QMessageBox>
#include <QDesktopServices>
#include <QIcon>
#include <QTimer>

// Includes everything needed for the program to function

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_server(nullptr)
    , m_isServerMode(false)
    , m_clientSocket(nullptr)
    , m_isConnected(false)
    , m_networkManager(new QNetworkAccessManager(this))
    , m_warningShown(false)
    , m_connectionTimer(nullptr)
{
    ui->setupUi(this);

    // Set window icon from resources
    setWindowIcon(QIcon(":/logo.png"));

    setupConnections();
    updateUI();
}

// initializes everything that is needed

MainWindow::~MainWindow()
{
    if (m_connectionTimer) {
        m_connectionTimer->stop();
        delete m_connectionTimer;
        m_connectionTimer = nullptr;
    }

    if (m_server) {
        stopServer();
    }
    if (m_clientSocket) {
        disconnectFromServer();
    }
    delete ui;
}

// Destructor which is called when the window is closed

void MainWindow::setupConnections()
{
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::on_connectButton_clicked);
    connect(ui->disconnectButton, &QPushButton::clicked, this, &MainWindow::on_disconnectButton_clicked);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);
    connect(ui->messageLineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_messageLineEdit_returnPressed);
}

//  connects UI elements to their respective handler functions using Qt's signal-slot

void MainWindow::on_actionStart_server_LAN_triggered()
{
    startServer("LAN");
}

// If action start server in menu is pressed it calls the method startserver on LAN side

void MainWindow::on_actionStart_server_WAN_triggered()
{
    startServer("WAN");
}

// If action start server in menu is pressed it calls the method startserver on WAN side

void MainWindow::on_actionAbout_triggered()
{
    QString aboutText =
        "<h2>🔒 CyberChat</h2>"
        "<p><b>Version:</b> 1.0</p>"
        "<p><b>Description:</b> A Qt-based chat application that supports both LAN and WAN connections. "
        "Users can host servers or connect as clients to communicate in real-time.</p>"
        "<p><b>Features:</b></p>"
        "<ul>"
        "<li>LAN and WAN server hosting</li>"
        "<li>Real-time messaging</li>"
        "<li>Connected users list</li>"
        "<li>Timestamped messages</li>"
        "<li>JSON-based communication protocol</li>"
        "</ul>"
        "<p><b>Built with:</b> Qt Framework</p>"
        "<p><b>GitHub Repository:</b> <a href='https://github.com/CyberNilsen/CyberChat'>https://github.com/CyberNilsen/CyberChat</a></p>"
        "<p><i>Click the GitHub link to visit the repository</i></p>";

    QMessageBox aboutBox(this);
    aboutBox.setWindowTitle("About CyberChat");
    aboutBox.setWindowIcon(QIcon(":/logo32.png")); // Set icon for the about dialog
    aboutBox.setTextFormat(Qt::RichText);
    aboutBox.setText(aboutText);
    aboutBox.setStandardButtons(QMessageBox::Ok);
    aboutBox.setTextInteractionFlags(Qt::TextBrowserInteraction);

    // Show the dialog and check if a link was clicked
    aboutBox.exec();
}

void MainWindow::startServer(const QString& mode)
{
    if (m_server) {
        stopServer();
    }
    // Start the server, if the server is already running we stop that server and start a new one

    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &MainWindow::onNewConnection);

    // The server relies on qt framework

    quint16 port = ui->portLineEdit->text().toUInt();
    if (port == 0) port = 8080;

    // Server port

    QHostAddress bindAddress = QHostAddress::Any;

    if (m_server->listen(bindAddress, port)) {
        m_isServerMode = true;
        m_serverMode = mode;
        QString localIP = getLocalIPAddress();
        QString message;

        // Here we say that the server listens to every adress so its open for every adress

        if (mode == "LAN") {
            message = QString("LAN Server started on port %1 and local IP %2").arg(port).arg(localIP);
            addChatMessage(message);
            addChatMessage("Other devices on your network can connect using: " + localIP + ":" + QString::number(port));
            ui->statusbar->showMessage(QString("LAN Server running on %1:%2").arg(localIP).arg(port));

            // if the server starts in LAN mode we write server ip adress and port to the GUI

        } else {
            message = QString("WAN Server started on port %1 and local IP %2").arg(port).arg(localIP);
            addChatMessage(message);
            addChatMessage("Getting public IP address...");
            ui->statusbar->showMessage(QString("WAN Server running on %1:%2").arg(localIP).arg(port));
            getPublicIP();

            // if the server starts in WAN mode we write server ip adress and port to the GUI
        }
        updateUI();
    } else {
        QMessageBox::critical(this, "Server Error",
                              QString("Failed to start server: %1").arg(m_server->errorString()));
        delete m_server;
        m_server = nullptr;

        // If we cant start the server we get a error message and we also stop the server
    }
}

void MainWindow::getPublicIP()
{
    QNetworkRequest request(QUrl("https://api.ipify.org"));
    QNetworkReply* reply = m_networkManager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString publicIP = reply->readAll().trimmed();
            QString message = QString("Public IP: %1 - Configure port forwarding on your router").arg(publicIP);
            addChatMessage(message);
        } else {
            addChatMessage("Could not retrieve public IP address");
        }
        reply->deleteLater();
    });

    // Here we fetch the public ip and display it in the GUI
}

void MainWindow::on_actionStop_server_triggered()
{
    stopServer();
}

// If stop server button is pressed we call the method stopserver

void MainWindow::stopServer()
{
    if (m_server) {
        // Disconnect all clients gracefully
        for (const auto& client : m_clients) {
            if (client.socket && client.socket->state() == QTcpSocket::ConnectedState) {
                client.socket->disconnectFromHost();
                if (!client.socket->waitForDisconnected(1000)) {
                    client.socket->abort();
                }
            }
        }
        m_clients.clear();

        m_server->close();
        delete m_server;
        m_server = nullptr;

        m_isServerMode = false;
        addChatMessage("Server stopped.");
        ui->statusbar->clearMessage();
        updateUsersList();
        updateUI();

        // Here is the method to stop the server, here we disconnect all clients, and stop the server
    }
}

void MainWindow::onNewConnection()
{
    if (!m_server) return;

    QTcpSocket* clientSocket = m_server->nextPendingConnection();
    if (!clientSocket) return;

    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::onClientDataReceived);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::onClientDisconnected);

    ConnectedClient client;
    client.socket = clientSocket;
    client.address = clientSocket->peerAddress().toString();
    client.username = "";

    m_clients.append(client);

    addChatMessage(QString("New connection from %1").arg(client.address));

    // Here the server accepts a client
}

void MainWindow::onClientDisconnected()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    // Find and remove the client
    QString username;
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients[i].socket == clientSocket) {
            username = m_clients[i].username;
            m_clients.removeAt(i);
            break;
        }
    }

    if (!username.isEmpty()) {
        addChatMessage(QString("%1 disconnected").arg(username));

        // Notify other clients
        QJsonObject message = createMessage("user_left", "", username);
        broadcastMessage(message, clientSocket);
    }

    updateUsersList();
    clientSocket->deleteLater();
}

// If a client disconnects we tell the other clients in the server that, that client has left

void MainWindow::onClientDataReceived()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QByteArray data = clientSocket->readAll();
    if (data.isEmpty()) return;

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        return; // Ignore invalid JSON
    }

    if (!doc.isObject()) return;

    QJsonObject message = doc.object();

    QString type = message["type"].toString();
    QString content = message["content"].toString();
    QString username = message["username"].toString();

    if (type == "join") {
        // Update client username
        for (auto& client : m_clients) {
            if (client.socket == clientSocket) {
                client.username = username;
                break;
            }
        }

        // Here is what happens when a client joins, if the client sends a message the server recieves it

        addChatMessage(QString("%1 joined the chat").arg(username));
        updateUsersList();

        QJsonObject joinMessage = createMessage("user_joined", "", username);
        broadcastMessage(joinMessage, clientSocket);

        // Here we notify users in the server that a new client has joined/user

        QJsonArray usersArray;
        for (const auto& client : m_clients) {
            if (!client.username.isEmpty()) {
                usersArray.append(client.username);
            }
        }
        QJsonObject usersMessage = createMessage("users_list");
        usersMessage["users"] = usersArray;
        sendToClient(clientSocket, usersMessage);

    } else if (type == "message") {
        addChatMessage(QString("[%1]: %2").arg(username, content));
        broadcastMessage(message, clientSocket);
    }

    // Here is the connected users list that are connected to the server, and if the client types a message we broadcast that to the other clients
}

void MainWindow::broadcastMessage(const QJsonObject& message, QTcpSocket* sender)
{
    QJsonDocument doc(message);
    QByteArray data = doc.toJson(QJsonDocument::Compact);

    for (const auto& client : m_clients) {
        if (client.socket && client.socket != sender && client.socket->state() == QTcpSocket::ConnectedState) {
            client.socket->write(data);
            client.socket->flush();
        }
    }
}

// Here is the code to broadcast the messages that the users send

void MainWindow::sendToClient(QTcpSocket* client, const QJsonObject& message)
{
    if (client && client->state() == QTcpSocket::ConnectedState) {
        QJsonDocument doc(message);
        QByteArray data = doc.toJson(QJsonDocument::Compact);
        client->write(data);
        client->flush();
    }
}

// This is the code to send the broadcasted message further to the clients

void MainWindow::updateUsersList()
{
    ui->usersListWidget->clear();

    if (m_isServerMode) {
        for (const auto& client : m_clients) {
            if (!client.username.isEmpty()) {
                ui->usersListWidget->addItem(client.username);
            }
        }
    }
}

// if a user joins then the connected users get updated

void MainWindow::addChatMessage(const QString& message)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString formattedMessage = QString("[%1] %2").arg(timestamp, message);
    ui->chatDisplayTextEdit->append(formattedMessage);
}

// The message that the users send get a timestamp and is also formatted, timestamp and then the message

QString MainWindow::getLocalIPAddress()
{
    QString localIP;

    QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
    for (const QHostAddress& address : addresses) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol &&
            !address.isLoopback() &&
            address != QHostAddress::LocalHost) {
            localIP = address.toString();
            break;
        }
    }

    if (localIP.isEmpty()) {
        localIP = "127.0.0.1";
    }

    return localIP;
}

// Here is the code to get the local IP adress of the server

void MainWindow::updateUI()
{
    bool isServerRunning = (m_server && m_server->isListening());

    ui->connectButton->setEnabled(!isServerRunning && !m_isConnected);
    ui->disconnectButton->setEnabled(isServerRunning || m_isConnected);
    ui->sendButton->setEnabled(isServerRunning || m_isConnected);
    ui->messageLineEdit->setEnabled(isServerRunning || m_isConnected);
}

// Here we update the UI in realtime when changes are made, new messages and etc

QJsonObject MainWindow::createMessage(const QString& type, const QString& content, const QString& username)
{
    QJsonObject message;
    message["type"] = type;
    message["content"] = content;
    message["username"] = username;
    message["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    return message;
}

// When the user sends a message this is what the message consists off or rather the data that gets sent to the server

void MainWindow::on_actionExit_triggered() { close(); }
void MainWindow::on_actionNew_Connection_triggered() {}

void MainWindow::on_connectButton_clicked()
{
    connectToServer();
}

// Here is what happens when the connect button is pressed. Then it calls upon the connect to server method

void MainWindow::connectToServer()
{
    if (m_clientSocket && m_clientSocket->state() != QAbstractSocket::UnconnectedState) {
        return;
    }

    // Clean up existing connection if any
    if (m_clientSocket) {
        disconnectFromServer();
    }

    QString serverIP = ui->ipLineEdit->text().trimmed();
    quint16 port = ui->portLineEdit->text().toUInt();
    m_username = ui->usernameLineEdit->text().trimmed();

    // Validate input - Fixed double message box issue
    if (serverIP.isEmpty() || port == 0 || m_username.isEmpty()) {
        if (!m_warningShown) {
            m_warningShown = true;
            QMessageBox::warning(this, "Input Error", "Please enter a valid IP address, port, and username.");
            // Reset warning flag after a short delay
            QTimer::singleShot(500, this, [this]() {
                m_warningShown = false;
            });
        }
        return;
    }

    if (port < 1024 || port > 65535) {
        QMessageBox::warning(this, "Port Error", "Please enter a port between 1024 and 65535.");
        return;
    }

    ui->connectButton->setEnabled(false);
    addChatMessage("Connecting to server...");

    m_clientSocket = new QTcpSocket(this);

    connect(m_clientSocket, &QTcpSocket::connected, this, &MainWindow::onConnectedToServer);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnectedFromServer);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &MainWindow::onServerDataReceived);
    connect(m_clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
            this, &MainWindow::onSocketError);

    // Clean up old timer if exists
    if (m_connectionTimer) {
        m_connectionTimer->stop();
        delete m_connectionTimer;
    }

    // Create connection timeout timer
    m_connectionTimer = new QTimer(this);
    m_connectionTimer->setSingleShot(true);
    connect(m_connectionTimer, &QTimer::timeout, this, [this]() {
        if (m_clientSocket && m_clientSocket->state() == QAbstractSocket::ConnectingState) {
            addChatMessage("Connection timeout. Please check the server address and try again.");
            disconnectFromServer();
        }
    });
    m_connectionTimer->start(10000); // 10 second timeout

    m_clientSocket->connectToHost(serverIP, port);
}

// Here is the connectToServer method. Here it essentially connects to the server.

void MainWindow::on_disconnectButton_clicked()
{
    disconnectFromServer();
}

void MainWindow::on_sendButton_clicked()
{
    if (!m_clientSocket || !m_isConnected || m_clientSocket->state() != QTcpSocket::ConnectedState) {
        addChatMessage("Error: Not connected to server.");
        return;
    }

    QString messageText = ui->messageLineEdit->text().trimmed();
    if (messageText.isEmpty()) {
        return;
    }

    if (messageText.length() > 1000) {
        QMessageBox::warning(this, "Message Too Long", "Please keep messages under 1000 characters.");
        return;
    }

    try {
        QJsonObject message = createMessage("message", messageText, m_username);
        QJsonDocument doc(message);
        QByteArray data = doc.toJson(QJsonDocument::Compact);

        qint64 bytesWritten = m_clientSocket->write(data);
        if (bytesWritten == -1) {
            addChatMessage("Error: Failed to send message.");
            return;
        }

        m_clientSocket->flush();
        ui->messageLineEdit->clear();

    } catch (const std::exception& e) {
        addChatMessage("Error: Failed to create message.");
    }
}

void MainWindow::on_messageLineEdit_returnPressed()
{
    if (ui->sendButton->isEnabled() && m_isConnected) {
        on_sendButton_clicked();
    }
}

void MainWindow::onConnectedToServer()
{
    if (m_connectionTimer) {
        m_connectionTimer->stop();
    }

    if (!m_clientSocket) {
        addChatMessage("Error: Lost connection during handshake.");
        ui->connectButton->setEnabled(true);
        return;
    }

    m_isConnected = true;
    updateUI();
    addChatMessage("Connected to server successfully.");

    try {
        QJsonObject joinMessage = createMessage("join", "", m_username);
        QJsonDocument doc(joinMessage);
        QByteArray data = doc.toJson(QJsonDocument::Compact);

        if (m_clientSocket->state() == QTcpSocket::ConnectedState) {
            qint64 bytesWritten = m_clientSocket->write(data);
            if (bytesWritten == -1) {
                addChatMessage("Error: Failed to send join message.");
                disconnectFromServer();
                return;
            }
            m_clientSocket->flush();
        }
    } catch (const std::exception& e) {
        addChatMessage("Error: Failed to create join message.");
        disconnectFromServer();
    }
}

void MainWindow::onDisconnectedFromServer()
{
    if (m_connectionTimer) {
        m_connectionTimer->stop();
    }

    m_isConnected = false;

    if (m_clientSocket) {

        disconnect(m_clientSocket, nullptr, this, nullptr);
        m_clientSocket->deleteLater();
        m_clientSocket = nullptr;
    }

    ui->usersListWidget->clear();
    ui->connectButton->setEnabled(true);

    updateUI();
    addChatMessage("Disconnected from server.");
}

void MainWindow::onServerDataReceived()
{
    if (!m_clientSocket) return;

    QByteArray data = m_clientSocket->readAll();
    if (data.isEmpty()) return;

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        addChatMessage("Error: Received invalid data from server.");
        return;
    }

    if (!doc.isObject()) {
        addChatMessage("Error: Received malformed message from server.");
        return;
    }

    QJsonObject message = doc.object();

    if (!message.contains("type")) {
        addChatMessage("Error: Received message without type field.");
        return;
    }

    QString type = message["type"].toString();
    QString content = message["content"].toString();
    QString username = message["username"].toString();

    try {
        if (type == "user_joined") {
            if (!username.isEmpty()) {
                addChatMessage(QString("%1 joined the chat.").arg(username));
            }
        } else if (type == "user_left") {
            if (!username.isEmpty()) {
                addChatMessage(QString("%1 left the chat.").arg(username));
            }
        } else if (type == "message") {
            if (!username.isEmpty() && !content.isEmpty()) {
                addChatMessage(QString("[%1]: %2").arg(username, content));
            }
        } else if (type == "users_list") {
            ui->usersListWidget->clear();
            if (message.contains("users") && message["users"].isArray()) {
                QJsonArray users = message["users"].toArray();
                for (const QJsonValue& user : users) {
                    if (user.isString() && !user.toString().isEmpty()) {
                        ui->usersListWidget->addItem(user.toString());
                    }
                }
            }
        } else {
            addChatMessage(QString("Received unknown message type: %1").arg(type));
        }
    } catch (const std::exception& e) {
        addChatMessage("Error processing server message.");
    }
}

void MainWindow::onSocketError(QAbstractSocket::SocketError error)
{
    if (m_connectionTimer) {
        m_connectionTimer->stop();
    }

    QString errorMessage;

    switch (error) {
    case QAbstractSocket::ConnectionRefusedError:
        errorMessage = "Connection refused. Check if server is running.";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        errorMessage = "Server closed the connection.";
        break;
    case QAbstractSocket::HostNotFoundError:
        errorMessage = "Host not found. Check the IP address.";
        break;
    case QAbstractSocket::SocketTimeoutError:
        errorMessage = "Connection timed out.";
        break;
    case QAbstractSocket::NetworkError:
        errorMessage = "Network error occurred.";
        break;
    case QAbstractSocket::SocketAccessError:
        errorMessage = "Socket access error. Check permissions.";
        break;
    default:
        if (m_clientSocket) {
            errorMessage = m_clientSocket->errorString();
        } else {
            errorMessage = "Unknown socket error occurred.";
        }
        break;
    }

    addChatMessage(QString("Connection Error: %1").arg(errorMessage));
    disconnectFromServer();
}

void MainWindow::disconnectFromServer()
{
    if (m_connectionTimer) {
        m_connectionTimer->stop();
    }

    if (m_clientSocket) {

        disconnect(m_clientSocket, nullptr, this, nullptr);

        if (m_clientSocket->state() == QTcpSocket::ConnectedState) {
            m_clientSocket->disconnectFromHost();
            if (!m_clientSocket->waitForDisconnected(3000)) {
                m_clientSocket->abort();
            }
        }

        m_clientSocket->deleteLater();
        m_clientSocket = nullptr;
    }

    m_isConnected = false;
    ui->usersListWidget->clear();
    ui->connectButton->setEnabled(true);
    updateUI();

    static bool disconnectMessageShown = false;
    if (!disconnectMessageShown) {
        disconnectMessageShown = true;
        // Reset flag after short delay
        QTimer::singleShot(100, []() { disconnectMessageShown = false; });
    }
}

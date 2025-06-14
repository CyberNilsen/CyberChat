#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QTimer>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextStream>
#include <QDateTime>
#include <QList>
#include <QNetworkAccessManager>

// Above are all the libraries we need for the program to function

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// QT namespace where qt stuff is

struct ConnectedClient {
    QTcpSocket* socket;
    QString username;
    QString address;
};

// data structure to store information about each connected client, like the network connection, username and ip adress of the client

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// This is the mainwindow or the application window

private slots:

    void on_actionStart_server_LAN_triggered();
    void on_actionStart_server_WAN_triggered();
    void on_actionStop_server_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionNew_Connection_triggered();

    // These are the menu choices. These are connected to the UI

    void on_connectButton_clicked();
    void on_disconnectButton_clicked();
    void on_sendButton_clicked();
    void on_messageLineEdit_returnPressed();

    // These are the buttons in the UI window/the client side

    void onNewConnection();
    void onClientDisconnected();
    void onClientDataReceived();

    // Server event handlers

    void onConnectedToServer();
    void onDisconnectedFromServer();
    void onServerDataReceived();
    void onSocketError(QAbstractSocket::SocketError error);

    // Client event handlers

private:
    Ui::MainWindow *ui;

    // The class here points to the whole UI which allows me to build the UI with the help of QT

    QTcpServer* m_server;
    QList<ConnectedClient> m_clients;
    bool m_isServerMode;
    QString m_serverMode;

    // Server components

    QTcpSocket* m_clientSocket;
    bool m_isConnected;
    QString m_username;

    // Client components

    void setupConnections();
    void startServer(const QString& mode);
    void stopServer();
    void broadcastMessage(const QJsonObject& message, QTcpSocket* sender = nullptr);
    void sendToClient(QTcpSocket* client, const QJsonObject& message);
    void updateUsersList();
    void addChatMessage(const QString& message);
    QString getLocalIPAddress();
    void updateUI();
    void connectToServer();
    void disconnectFromServer();
    QJsonObject createMessage(const QString& type, const QString& content = "", const QString& username = "");
    QNetworkAccessManager* m_networkManager;
    void getPublicIP();
    bool m_warningShown;
    QTimer* m_connectionTimer;

    // Here are methods where i can start/stop server and etc


};

#endif // MAINWINDOW_H

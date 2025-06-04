/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Connection;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_left;
    QLabel *titleLabel;
    QGroupBox *connectionGroup;
    QVBoxLayout *verticalLayout_connection;
    QLabel *modeLabel;
    QComboBox *modeComboBox;
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QHBoxLayout *connectionButtonsLayout;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QGroupBox *usersGroup;
    QVBoxLayout *verticalLayout_users;
    QListWidget *usersListWidget;
    QSpacerItem *verticalSpacer;
    QWidget *chatPanel;
    QVBoxLayout *verticalLayout_chat;
    QLabel *chatHeaderLabel;
    QTextEdit *chatDisplayTextEdit;
    QWidget *messageInputWidget;
    QHBoxLayout *horizontalLayout_input;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 666);
        actionNew_Connection = new QAction(MainWindow);
        actionNew_Connection->setObjectName("actionNew_Connection");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setSpacing(10);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        horizontalLayout_main->setContentsMargins(10, 10, 10, 10);
        leftPanel = new QWidget(centralwidget);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setMaximumSize(QSize(280, 16777215));
        verticalLayout_left = new QVBoxLayout(leftPanel);
        verticalLayout_left->setObjectName("verticalLayout_left");
        titleLabel = new QLabel(leftPanel);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_left->addWidget(titleLabel);

        connectionGroup = new QGroupBox(leftPanel);
        connectionGroup->setObjectName("connectionGroup");
        verticalLayout_connection = new QVBoxLayout(connectionGroup);
        verticalLayout_connection->setObjectName("verticalLayout_connection");
        modeLabel = new QLabel(connectionGroup);
        modeLabel->setObjectName("modeLabel");

        verticalLayout_connection->addWidget(modeLabel);

        modeComboBox = new QComboBox(connectionGroup);
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->setObjectName("modeComboBox");

        verticalLayout_connection->addWidget(modeComboBox);

        ipLabel = new QLabel(connectionGroup);
        ipLabel->setObjectName("ipLabel");

        verticalLayout_connection->addWidget(ipLabel);

        ipLineEdit = new QLineEdit(connectionGroup);
        ipLineEdit->setObjectName("ipLineEdit");

        verticalLayout_connection->addWidget(ipLineEdit);

        portLabel = new QLabel(connectionGroup);
        portLabel->setObjectName("portLabel");

        verticalLayout_connection->addWidget(portLabel);

        portLineEdit = new QLineEdit(connectionGroup);
        portLineEdit->setObjectName("portLineEdit");

        verticalLayout_connection->addWidget(portLineEdit);

        connectionButtonsLayout = new QHBoxLayout();
        connectionButtonsLayout->setObjectName("connectionButtonsLayout");
        connectButton = new QPushButton(connectionGroup);
        connectButton->setObjectName("connectButton");

        connectionButtonsLayout->addWidget(connectButton);

        disconnectButton = new QPushButton(connectionGroup);
        disconnectButton->setObjectName("disconnectButton");
        disconnectButton->setEnabled(false);

        connectionButtonsLayout->addWidget(disconnectButton);


        verticalLayout_connection->addLayout(connectionButtonsLayout);


        verticalLayout_left->addWidget(connectionGroup);

        usersGroup = new QGroupBox(leftPanel);
        usersGroup->setObjectName("usersGroup");
        verticalLayout_users = new QVBoxLayout(usersGroup);
        verticalLayout_users->setObjectName("verticalLayout_users");
        usersListWidget = new QListWidget(usersGroup);
        usersListWidget->setObjectName("usersListWidget");
        usersListWidget->setAlternatingRowColors(true);

        verticalLayout_users->addWidget(usersListWidget);


        verticalLayout_left->addWidget(usersGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_left->addItem(verticalSpacer);


        horizontalLayout_main->addWidget(leftPanel);

        chatPanel = new QWidget(centralwidget);
        chatPanel->setObjectName("chatPanel");
        verticalLayout_chat = new QVBoxLayout(chatPanel);
        verticalLayout_chat->setObjectName("verticalLayout_chat");
        chatHeaderLabel = new QLabel(chatPanel);
        chatHeaderLabel->setObjectName("chatHeaderLabel");

        verticalLayout_chat->addWidget(chatHeaderLabel);

        chatDisplayTextEdit = new QTextEdit(chatPanel);
        chatDisplayTextEdit->setObjectName("chatDisplayTextEdit");
        chatDisplayTextEdit->setReadOnly(true);

        verticalLayout_chat->addWidget(chatDisplayTextEdit);

        messageInputWidget = new QWidget(chatPanel);
        messageInputWidget->setObjectName("messageInputWidget");
        horizontalLayout_input = new QHBoxLayout(messageInputWidget);
        horizontalLayout_input->setSpacing(10);
        horizontalLayout_input->setObjectName("horizontalLayout_input");
        messageLineEdit = new QLineEdit(messageInputWidget);
        messageLineEdit->setObjectName("messageLineEdit");

        horizontalLayout_input->addWidget(messageLineEdit);

        sendButton = new QPushButton(messageInputWidget);
        sendButton->setObjectName("sendButton");
        sendButton->setEnabled(false);
        sendButton->setMinimumSize(QSize(80, 0));

        horizontalLayout_input->addWidget(sendButton);


        verticalLayout_chat->addWidget(messageInputWidget);


        horizontalLayout_main->addWidget(chatPanel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 28));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(modeComboBox, ipLineEdit);
        QWidget::setTabOrder(ipLineEdit, portLineEdit);
        QWidget::setTabOrder(portLineEdit, connectButton);
        QWidget::setTabOrder(connectButton, disconnectButton);
        QWidget::setTabOrder(disconnectButton, messageLineEdit);
        QWidget::setTabOrder(messageLineEdit, sendButton);
        QWidget::setTabOrder(sendButton, chatDisplayTextEdit);
        QWidget::setTabOrder(chatDisplayTextEdit, usersListWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Connection);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CyberChat - Secure Anonymous Messaging", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "QMainWindow {\n"
"    background-color: #1e1e1e;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QWidget {\n"
"    background-color: #1e1e1e;\n"
"    color: #ffffff;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}\n"
"\n"
"/* Chat Area Styling */\n"
"QTextEdit {\n"
"    background-color: #2d2d2d;\n"
"    border: 1px solid #404040;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 2px solid #00d4aa;\n"
"}\n"
"\n"
"/* Input Field Styling */\n"
"QLineEdit {\n"
"    background-color: #2d2d2d;\n"
"    border: 1px solid #404040;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00d4aa;\n"
"    background-color: #363636;\n"
"}\n"
"\n"
"/* Button Styling */\n"
"QPushButton {\n"
"    background-color: #00d4aa;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;"
                        "\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00b894;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #00a085;\n"
"}\n"
"\n"
"QPushButton#disconnectButton {\n"
"    background-color: #e74c3c;\n"
"}\n"
"\n"
"QPushButton#disconnectButton:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"\n"
"/* List Widget Styling */\n"
"QListWidget {\n"
"    background-color: #2d2d2d;\n"
"    border: 1px solid #404040;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #00d4aa;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #404040;\n"
"}\n"
"\n"
"/* Label Styling */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color:"
                        " #00d4aa;\n"
"}\n"
"\n"
"/* Status Bar Styling */\n"
"QStatusBar {\n"
"    background-color: #2d2d2d;\n"
"    border-top: 1px solid #404040;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"/* Group Box Styling */\n"
"QGroupBox {\n"
"    border: 1px solid #404040;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"    font-weight: bold;\n"
"    color: #00d4aa;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"}", nullptr));
        actionNew_Connection->setText(QCoreApplication::translate("MainWindow", "New Connection", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Connection->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About CyberChat", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\224\222 CyberChat", nullptr));
        connectionGroup->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        modeLabel->setText(QCoreApplication::translate("MainWindow", "Mode:", nullptr));
        modeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "LAN Mode", nullptr));
        modeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "WAN Mode (Server)", nullptr));
        modeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "WAN Mode (Client)", nullptr));

        modeComboBox->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox {\n"
"    background-color: #2d2d2d;\n"
"    border: 1px solid #404040;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow_down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2d2d2d;\n"
"    border: 1px solid #404040;\n"
"    selection-background-color: #00d4aa;\n"
"}", nullptr));
        ipLabel->setText(QCoreApplication::translate("MainWindow", "IP Address:", nullptr));
        ipLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter IP address...", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        portLineEdit->setText(QCoreApplication::translate("MainWindow", "8080", nullptr));
        portLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Port number", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        usersGroup->setTitle(QCoreApplication::translate("MainWindow", "Connected Users", nullptr));
        chatHeaderLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; font-weight: bold; color: #00d4aa; padding: 5px;", nullptr));
        chatHeaderLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\222\254 Secure Chat Room", nullptr));
        chatDisplayTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Welcome to CyberChat! Connect to start secure messaging...", nullptr));
        messageLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type your message here...", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        menubar->setStyleSheet(QCoreApplication::translate("MainWindow", "QMenuBar {\n"
"    background-color: #2d2d2d;\n"
"    color: #ffffff;\n"
"    border-bottom: 1px solid #404040;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #00d4aa;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #2d2d2d;\n"
"    color: #ffffff;\n"
"    border: 1px solid #404040;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #00d4aa;\n"
"}", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        statusbar->setStyleSheet(QCoreApplication::translate("MainWindow", "QStatusBar {\n"
"    background-color: #2d2d2d;\n"
"    border-top: 1px solid #404040;\n"
"    color: #ffffff;\n"
"}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

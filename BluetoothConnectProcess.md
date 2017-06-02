## Chat server:
  - create an instance of QRfcommServer to listen for incoming Bluetooth connections is rfcommServer
    + connect(rfcommServer, SIGNAL(newConnection()), myChatServer, SLOT(clientConnected()));
      * In myChatServer slot clientConnected -> emit myChatServer  signal clientConnected
  - After client connect: (in slot clientConnected) Create an instance of QBluetoothSocket is socket
    + connect(socket, SIGNAL(readyRead()), myChatServer, SLOT(readSocket()));
    + connect(socket, SIGNAL(disconnected()), myChatServer, SLOT(clientDisconnected()));

## Chat client
  - Create an instance of QBluetoothSocket is socket and connect it to Chat server
    + connect(socket, SIGNAL(readyRead()), myChatClient, SLOT(readSocket()));
    + connect(socket, SIGNAL(connected()), myChatClient, SLOT(connected()));
      * In myChatClient slot connected -> emit myChatClient signal connected
    + connect(socket, SIGNAL(disconnected()), myChatClient, SIGNAL(disconnected()));

## Chat dialog
  - Overview
    + connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));
    + connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectClicked()));
      * connectClicked: star service discovery and search all 
    + connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendClicked()));
      * sendClicked: emit Chat sendMessage
    + connect(ui->firstAdapter, SIGNAL(clicked()), this, SLOT(newAdapterSelected()));
  - Create an instance of myChatServer is server
    + connect(server, SIGNAL(clientConnected(QString)), Chat, SLOT(clientConnected(QString)));
      * clientConnected: display "X has connected"
    + connect(server, SIGNAL(clientDisconnected(QString)), Chat, SLOT(clientDisconnected(QString)));
      * clientDisconnected: display "X has disconnected "
    + connect(server, SIGNAL(messageReceived(QString,QString)), Chat, SLOT(showMessage(QString,QString)));
      * showMessage: display message
    + connect(Chat, SIGNAL(sendMessage(QString)), server, SLOT(sendMessage(QString)));
  - When connect button being clicked, search server and create client
    + connect(client, SIGNAL(messageReceived(QString,QString)),Chat, SLOT(showMessage(QString,QString)));
    + connect(client, SIGNAL(disconnected()), Chat, SLOT(clientDisconnected()));
    + connect(client, SIGNAL(connected(QString)), Chat, SLOT(connected(QString)));
      * Connected: Display "Join chat with X"
    + connect(Chat, SIGNAL(sendMessage(QString)), client, SLOT(sendMessage(QString)));

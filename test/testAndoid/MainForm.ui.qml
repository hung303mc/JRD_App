import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 640
    height: 480
    property alias bubble: bubble
    property alias mainWindow: mainWindow

    Rectangle {
        id: mainWindow
        color: "#ffffff"
        anchors.fill: parent

        Bubble {
            id: bubble
            x: 278
            y: 198
        }
    }
}

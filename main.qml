import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 200
        color: "red"
    }
}

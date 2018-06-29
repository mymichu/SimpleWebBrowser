import QtQuick 2.11
import QtQuick.Window 2.11


Window {
    id: mainWindow
    objectName: "mainWindow"
    property string path: "www.google.ch"
    visible: true
    width: 640
    height: 480
    title: qsTr("Simple Webrowser")

    Loader {
        objectName: "loader"
        anchors.fill: parent
        id: pageLoader
        z: -1
    }

    Rectangle{
        id: browserState
        objectName: "browserState"
        anchors.fill: parent
        color: "lightgrey"
        Component.onCompleted: loadTimer.start()
        z: -2
    }


    Timer {
        id: loadTimer
        interval: 1000; running: false; repeat: false
        onTriggered: pageLoader.source = "browserview.qml"
    }

}

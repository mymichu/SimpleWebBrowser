import QtQuick 2.11
import QtQuick.Window 2.11
import QtWebEngine 1.0
import simpleBrowser.Backend 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Simple Webrowser")
    BackendBrowser{
        id:backenBrowser
    }

    WebEngineView {
        anchors.fill: parent
        url: backenBrowser.urlPath
    }
}

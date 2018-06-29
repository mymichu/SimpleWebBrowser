import QtQuick 2.0
import QtWebEngine 1.0
import simpleBrowser.Backend 1.0

Rectangle {
    visible: true
    width: 640
    height: 480
    Component.onCompleted: console.log("HELLO COMPONENT");
    BackendBrowser{
        id:backenBrowser
        objectName: "backendBrowser"
        onUrlPathChanged: function hi(){
                            console.log("HELLO CHANGE");
                            webview.url = backenBrowser.urlPath}

    }

    Keys.onDigit0Pressed: {
        webview.reload();
    }

    Rectangle{
        id:browserState
        property variant textBrowserState: ["Loading", "Loaded", "Connection Error"]
        property int connectionState: 0 //0 = Loading, 1 = Loaded, 2 = Connection Error
        anchors.fill: parent
        color: "#000000"
        z:3
        visible: connectionState !=1 ? true : false


        Text{
            color: "#ffffff"
            text: browserState.textBrowserState[browserState.connectionState]
            font.pointSize: 20
            fontSizeMode: Text.FixedSize
            lineHeight: 1
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent

        }
    }

    WebEngineView {
        id: webview
        anchors.fill: parent
        url: backenBrowser.urlPath
        z:2
        onLoadingChanged: function(loadRequested){
            console.log("HELLO "+loadRequested.errorString);
            switch(loadRequested.status){
            case WebEngineLoadRequest.LoadStartedStatus:
                console.log("Loading Started");
                browserState.connectionState = 0;
                break;
            case WebEngineLoadRequest.LoadSucceededStatus:
                console.log("Loading Succeeded");
                browserState.connectionState = 1;
                break;
            case WebEngineLoadRequest.LoadFailedStatus:
                console.log("Loading Failed");
                browserState.connectionState = 2;
                break;
            }
        }
    }
}

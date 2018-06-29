var component;

function createSpriteObjects() {
        component = Qt.createComponent("browserview.qml");
        if (component.status === Component.Ready)
            finishCreation();
        else
            component.statusChanged.connect(finishCreation);
    }
}

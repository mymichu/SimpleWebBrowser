#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine/QtWebEngine>
#include "QMLBackend/qtbrowser.h"
#include "QMLObjectHander/qtfrontendobjecthandler.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QtFrontendObjectHandler* handler = QtFrontendObjectHandler::getInstance();

    if(argc>0)
    {
        handler->setURL(argv[1]);
    }
    {
        handler->setURL("http://localhost");
    }

    QtWebEngine::initialize();
    qmlRegisterType<QMLBackend::QtBrowser>("simpleBrowser.Backend",1,0,"BackendBrowser");
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    QList<QObject*>qmlObjects =  engine.rootObjects();

    qDebug()<<qmlObjects.length();

    return app.exec();
}

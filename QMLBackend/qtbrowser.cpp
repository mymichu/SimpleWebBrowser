#include "qtbrowser.h"
#include <QDebug>
#include "QMLObjectHander/qtfrontendobjecthandler.h"
using namespace QMLBackend;

QtBrowser::QtBrowser(QObject *parent):
    QObject(parent),
    m_urlPath("http://webglsamples.org/blob/blob.html")
{
    m_FrontEndHandler = QtFrontendObjectHandler::getInstance();
    m_urlPath = m_FrontEndHandler->getURL();
    qDebug()<<"URL: "<<m_urlPath;
}

QString QtBrowser::urlPath() const
{
    return m_urlPath;
}

void QtBrowser::setUrlPath(const QString &urlPath)
{
    if (urlPath == m_urlPath)
            return;
    qDebug()<<"HELLO";
    m_urlPath = urlPath;
    emit urlPathChanged();
}



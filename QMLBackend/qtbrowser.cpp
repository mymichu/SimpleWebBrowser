#include "qtbrowser.h"

using namespace QMLBackend;

QtBrowser::QtBrowser(QObject *parent):
    QObject(parent),
    m_urlPath("http://webglsamples.org/blob/blob.html")
{

}

QString QtBrowser::urlPath() const
{
    return m_urlPath;
}

void QtBrowser::setUrlPath(const QString &urlPath)
{
    m_urlPath = urlPath;
}



#include "qtfrontendobjecthandler.h"
#include <QDebug>

QtFrontendObjectHandler *QtFrontendObjectHandler::getInstance()
{
    if(m_Instance==NULL)
    {
        m_Instance = new QtFrontendObjectHandler();
    }
    return m_Instance;
}

void QtFrontendObjectHandler::setURL(const QString &a_URL)
{
    m_URL = a_URL;
}

QString QtFrontendObjectHandler::getURL() const
{
    return m_URL;
}

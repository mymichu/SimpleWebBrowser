#ifndef QTBROWSER_H
#define QTBROWSER_H

#include <QObject>
#include <QString>
class QtFrontendObjectHandler;
namespace QMLBackend {
class QtBrowser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString urlPath READ urlPath WRITE setUrlPath NOTIFY urlPathChanged)
public:
    explicit QtBrowser(QObject *parent = nullptr);
    QString urlPath() const;
    void setUrlPath(const QString &urlPath);

signals:
    void urlPathChanged();

private:
    QtFrontendObjectHandler* m_FrontEndHandler;
    QString m_urlPath;
};

}
#endif // QTBROWSER_H

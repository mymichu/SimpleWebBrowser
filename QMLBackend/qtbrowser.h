#ifndef QTBROWSER_H
#define QTBROWSER_H

#include <QObject>
#include <QString>
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
    QString m_urlPath;
};

}
#endif // QTBROWSER_H

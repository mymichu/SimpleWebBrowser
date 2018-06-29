#ifndef QTFRONTENDOBJECTHANDLER_H
#define QTFRONTENDOBJECTHANDLER_H

#include <QObject>



class QtFrontendObjectHandler : public QObject
{
    Q_OBJECT
public:
    static QtFrontendObjectHandler* getInstance();
    void setURL(const QString& a_URL);
    QString getURL() const;

private:
    QString m_URL;
signals:

public slots:
};

static QtFrontendObjectHandler* m_Instance;


#endif // QTFRONTENDOBJECTHANDLER_H

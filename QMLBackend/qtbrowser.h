#ifndef QTBROWSER_H
#define QTBROWSER_H

#include <QObject>

class QtBrowser : public QObject
{
    Q_OBJECT
public:
    explicit QtBrowser(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QTBROWSER_H
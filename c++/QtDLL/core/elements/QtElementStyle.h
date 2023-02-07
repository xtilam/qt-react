#ifndef QTELEMENTSTYLE_H
#define QTELEMENTSTYLE_H

#include <QObject>
#include <QMap>

class QtElementStyle : public QObject
{
    Q_OBJECT
public:
    bool isChange = false;
    QMap<QString, QString> cssProperties;
    explicit QtElementStyle(QObject *parent = nullptr);
    const QString getPropery(const QString & property);
    void setProperty(const QString & property,  const QString &value);
    const QString getStringStyle();
};

#endif // QTELEMENTSTYLE_H

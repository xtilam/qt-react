#include "QtElementStyle.h"
#include <QDebug>

QtElementStyle::QtElementStyle(QObject *parent) : QObject(parent)
{

}

const QString QtElementStyle::getPropery(const QString &property)
{

}

void QtElementStyle::setProperty(const QString &property, const QString &value)
{

}

const QString QtElementStyle::getStringStyle()
{
    QString style;
    for(auto iter = cssProperties.begin(); iter != cssProperties.end(); iter++){
        style.append(iter.key() + ":" + iter.value() + ";\n");
    }
    qDebug() << style;
    isChange = false;
    return style;
}

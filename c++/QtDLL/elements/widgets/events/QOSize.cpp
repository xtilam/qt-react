#include "QOSize.h"
#include <QDebug>

QOSize::QOSize(QObject *parent) : BaseQObjectConvert(parent)
{

}

QOSize * QOSize::setSize(QSize * size)
{
    this->size = size;
    this->setupComplete();
    return this;
}

QOSize *QOSize::setSize(const QSize *size)
{
    return this->setSize((QSize *)size);
}

int QOSize::width()
{
    qDebug() << *size;
    return size->width();
}

int QOSize::height()
{
    return size->height();
}

bool QOSize::isEmpty()
{
    return size->isEmpty();
}

bool QOSize::isNull()
{
    return size->isNull();
}

bool QOSize::isValid()
{
    return size->isValid();
}

int QOSize::rheight()
{
    return size->rheight();
}

int QOSize::rwidth()
{
    return size->rwidth();
}

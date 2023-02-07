#include "QOResizeEvent.h"
#include <QDebug>

QOResizeEvent::QOResizeEvent(QObject * parent) : QObject(parent)
{
}

QOResizeEvent *QOResizeEvent::setEvt(QResizeEvent *evt)
{
    this->evt = evt;
    return this;
}

void QOResizeEvent::oldSizeSetup()
{
    if(oldSize.isSetup()) return;
    oldSize.setSize(&evt->oldSize());
}

void QOResizeEvent::sizeSetup()
{
    if(size.isSetup()) return;
    size.setSize(&evt->size());
}

QOSize * QOResizeEvent::r_oldSize()
{
    this->oldSizeSetup();
    return &this->oldSize;
}

QOSize * QOResizeEvent::r_size()
{
    this->sizeSetup();
    return &this->size;
}

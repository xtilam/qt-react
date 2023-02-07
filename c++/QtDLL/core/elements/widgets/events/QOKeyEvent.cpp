#include "QOKeyEvent.h"

QOKeyEvent::QOKeyEvent(QObject *parent) : QObject(parent)
{

}

QOKeyEvent *QOKeyEvent::setEvt(QKeyEvent * evt)
{
    this->evt = evt;
    return this;
}

int QOKeyEvent::r_key()
{
    return evt->key();
}

int QOKeyEvent::r_count()
{
    return evt->count();
}

bool QOKeyEvent::r_isAutoRepeat()
{
//    evt->modifiers()
    return evt->isAutoRepeat();
}

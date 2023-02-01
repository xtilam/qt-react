#include "QOFocusEvent.h"

QOFocusEvent::QOFocusEvent(QObject *parent) : QObject(parent)
{

}

QOFocusEvent *QOFocusEvent::setEvt(QFocusEvent *evt)
{
    this->evt = evt;
    return this;
}

bool QOFocusEvent::r_gotFocus()
{
    return evt->gotFocus();
}

bool QOFocusEvent::r_lostFocus()
{
    return evt->lostFocus();
}

int QOFocusEvent::r_reason()
{
    return evt->reason();
}

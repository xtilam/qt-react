#include "QOMouseEvent.h"

QOMouseEvent::QOMouseEvent(QObject * parent) : QObject(parent)
{
}

QOMouseEvent *QOMouseEvent::setEvt(QMouseEvent *evt)
{
    this->evt = evt;
    return this;
}

QOPoint *QOMouseEvent::r_globalPos()
{
    if(!globalPos.isSetup()) globalPos.setData(evt->globalPos());
    return &globalPos;
}

QOPointF *QOMouseEvent::r_localPos()
{
    if(!localPos.isSetup()) localPos.setData(&evt->localPos());
    return &localPos;
}

QOPoint *QOMouseEvent::r_pos()
{
    if(!pos.isSetup()) pos.setData(evt->pos());
    return &pos;
}

QOPointF *QOMouseEvent::r_screenPos()
{
    if(!screenPos.isSetup()) screenPos.setData(&evt->screenPos());
    return &screenPos;
}

QOPointF *QOMouseEvent::r_windowPos()
{
    if(!windowPos.isSetup()) windowPos.setData(&evt->windowPos());
    return &windowPos;
}

int QOMouseEvent::r_x()
{
    return evt->x();
}

int QOMouseEvent::r_y()
{
    return evt->y();
}

int QOMouseEvent::r_button()
{
    return evt->button();
}

#include "QOPointF.h"

QOPointF::QOPointF(QObject *parent) : BaseQObjectConvert(parent)
{

}

void QOPointF::setData(QPointF *point)
{
    this->point = point;
    this->setupComplete();
}

void QOPointF::setData(const QPointF *point)
{
    setData((QPointF *)point);
}

qreal QOPointF::r_rx()
{
    return point->rx();
}

qreal QOPointF::r_ry()
{
    return point->ry();
}

qreal QOPointF::r_x()
{
    return point->x();
}

qreal QOPointF::r_y()
{
    return point->y();
}


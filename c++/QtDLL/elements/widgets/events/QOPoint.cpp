#include "QOPoint.h"

QOPoint::QOPoint(QObject *parent) : BaseQObjectConvert(parent)
{

}

void QOPoint::setData(const QPoint point)
{
    this->point = point;
    this->setupComplete();
}

int QOPoint::r_rx()
{
    return point.rx();
}

int QOPoint::r_ry()
{
    return point.ry();
}

int QOPoint::r_x()
{
    return point.x();
}

int QOPoint::r_y()
{
    return point.y();
}

#ifndef QOPOINTF_H
#define QOPOINTF_H

#include "BaseQObjectConvert.h"
#include <QPointF>

class QOPointF : public BaseQObjectConvert
{
    Q_OBJECT
public:
    QPointF * point;
    explicit QOPointF(QObject *parent = nullptr);
    void setData(QPointF * point);
    void setData(const QPointF * point);

    Q_PROPERTY(qreal rx READ r_rx)
    qreal r_rx();
    Q_PROPERTY(qreal ry READ r_ry)
    qreal r_ry();
    Q_PROPERTY(qreal x READ r_rx)
    qreal r_x();
    Q_PROPERTY(qreal y READ r_rx)
    qreal r_y();
};

#endif // QOPOINTF_H

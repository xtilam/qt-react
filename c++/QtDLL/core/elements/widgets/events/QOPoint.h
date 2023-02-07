#ifndef QOPOINT_H
#define QOPOINT_H

#include "BaseQObjectConvert.h"
#include <QPoint>

class QOPoint : public BaseQObjectConvert
{
    Q_OBJECT
public:
    QPoint point;
    explicit QOPoint(QObject *parent = nullptr);
    void setData(const QPoint point);

    Q_PROPERTY(int rx READ r_rx)
	int r_rx();
    Q_PROPERTY(int ry READ r_ry)
	int r_ry();
    Q_PROPERTY(int x READ r_rx)
	int r_x();
    Q_PROPERTY(int y READ r_rx)
	int r_y();

public slots:
};

#endif // QOPOINT_H

#ifndef QOMOUSEEVENT_H
#define QOMOUSEEVENT_H

#include <QObject>
#include <QMouseEvent>
#include "QOPoint.h"
#include "QOPointF.h"

class QOMouseEvent : public QObject
{
    Q_OBJECT
public:
    QMouseEvent * evt;
    explicit QOMouseEvent(QObject * parent = nullptr);
    QOMouseEvent * setEvt(QMouseEvent * evt);

	QOPoint globalPos;
    Q_PROPERTY(QOPoint * globalPos READ r_globalPos)
    QOPoint * r_globalPos();
    void setup_globalPos();

    QOPointF localPos;
    Q_PROPERTY(QOPointF * localPos READ r_localPos)
    QOPointF * r_localPos();

	QOPoint pos;
    Q_PROPERTY(QOPoint * pos READ r_pos)
    QOPoint * r_pos();

	QOPointF screenPos;
    Q_PROPERTY(QOPointF * screenPos READ r_screenPos)
    QOPointF * r_screenPos();

	QOPointF windowPos;
    Q_PROPERTY(QOPointF * windowPos READ r_windowPos)
    QOPointF * r_windowPos();

	Q_PROPERTY(int x READ r_x)
	int r_x();
	Q_PROPERTY(int y READ r_y)
	int r_y();
    Q_PROPERTY(int button READ r_button)
    int r_button();
public slots:
//    int pointCount();
//    bool allPointsAccepted();
//    bool allPointsGrabbed();
};

#endif // QOMOUSEEVENT_H

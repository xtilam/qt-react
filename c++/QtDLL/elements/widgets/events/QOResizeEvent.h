#ifndef QORESIZEEVENT_H
#define QORESIZEEVENT_H

#include <QObject>
#include <QResizeEvent>
#include "QOSize.h"

class QOResizeEvent : public QObject
{
    Q_OBJECT
public:
    QOSize oldSize;
    QOSize size;

    bool isSetup = false;
    QResizeEvent * evt;

    explicit QOResizeEvent(QObject * parent = nullptr);
    QOResizeEvent * setEvt(QResizeEvent * evt);

    void oldSizeSetup();
    void sizeSetup();

    Q_PROPERTY(QOSize * oldSize READ r_oldSize)
    QOSize * r_oldSize();

    Q_PROPERTY(QOSize * size READ r_size)
    QOSize * r_size();
};

#endif // QORESIZEEVENT_H

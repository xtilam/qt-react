#ifndef QOKEYEVENT_H
#define QOKEYEVENT_H

#include <QObject>
#include <QKeyEvent>

class QOKeyEvent : public QObject
{
    Q_OBJECT
public:
    QKeyEvent * evt;
    explicit QOKeyEvent(QObject *parent = nullptr);
    QOKeyEvent * setEvt(QKeyEvent * evt);

    Q_PROPERTY(int key READ r_key)
    int r_key();
    Q_PROPERTY(int count READ r_count)
    int r_count();
    Q_PROPERTY(bool isAutoRepeat READ r_isAutoRepeat)
    bool r_isAutoRepeat();
};

#endif // QOKEYEVENT_H

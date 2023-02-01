#ifndef QOFOCUSEVENT_H
#define QOFOCUSEVENT_H

#include <QObject>
#include <QFocusEvent>

class QOFocusEvent : public QObject
{
    Q_OBJECT
public:
    QFocusEvent * evt;
    explicit QOFocusEvent(QObject *parent = nullptr);
    QOFocusEvent * setEvt(QFocusEvent * evt);
	Q_PROPERTY(bool gotFocus READ r_gotFocus)
    bool r_gotFocus();
	Q_PROPERTY(bool lostFocus READ r_lostFocus)
    bool r_lostFocus();
    Q_PROPERTY(bool reason READ r_reason)
    int r_reason();
signals:

};

#endif // QOFOCUSEVENT_H

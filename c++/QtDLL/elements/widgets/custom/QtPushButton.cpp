#include "QtPushButton.h"

QtPushButton::QtPushButton(QWidget *parent) : QPushButton(parent)
{

}


void QtPushButton::mousePressEvent(QMouseEvent *event)
{
	emit evt_mousePressEvent(event);
}

void QtPushButton::mouseReleaseEvent(QMouseEvent *event)
{
	emit evt_mouseReleaseEvent(event);
}

void QtPushButton::mouseMoveEvent(QMouseEvent *event)
{
	emit evt_mouseMoveEvent(event);
}

void QtPushButton::keyPressEvent(QKeyEvent *event)
{
	emit evt_keyPressEvent(event);
}

void QtPushButton::keyReleaseEvent(QKeyEvent *event)
{
	emit evt_keyReleaseEvent(event);
}

void QtPushButton::focusInEvent(QFocusEvent *event)
{
	emit evt_focusInEvent(event);
}

void QtPushButton::focusOutEvent(QFocusEvent *event)
{
	emit evt_focusOutEvent(event);
}

#include "QWindowCustom.h"

QWindowCustom::QWindowCustom(QWidget *parent) : QMainWindow(parent)
{

}


void QWindowCustom::mousePressEvent(QMouseEvent *event)
{
	emit evt_mousePressEvent(event);
}

void QWindowCustom::mouseReleaseEvent(QMouseEvent *event)
{
	emit evt_mouseReleaseEvent(event);
}

void QWindowCustom::mouseDoubleClickEvent(QMouseEvent *event)
{
	emit evt_mouseDoubleClickEvent(event);
}

void QWindowCustom::mouseMoveEvent(QMouseEvent *event)
{
	emit evt_mouseMoveEvent(event);
}

void QWindowCustom::keyPressEvent(QKeyEvent *event)
{
	emit evt_keyPressEvent(event);
}

void QWindowCustom::keyReleaseEvent(QKeyEvent *event)
{
	emit evt_keyReleaseEvent(event);
}

void QWindowCustom::focusInEvent(QFocusEvent *event)
{
	emit evt_focusInEvent(event);
}

void QWindowCustom::focusOutEvent(QFocusEvent *event)
{
	emit evt_focusOutEvent(event);
}

void QWindowCustom::resizeEvent(QResizeEvent *event)
{
	emit evt_resizeEvent(event);
}

void QWindowCustom::closeEvent(QCloseEvent *event)
{
	emit evt_closeEvent(event);
}

void QWindowCustom::showEvent(QShowEvent *event)
{
	emit evt_showEvent(event);
}

void QWindowCustom::hideEvent(QHideEvent *event)
{
	emit evt_hideEvent(event);
}

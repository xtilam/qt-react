#include "QWidgetCustom.h"

QWidgetCustom::QWidgetCustom(QWidget *parent) : QWidget(parent)
{

}


void QWidgetCustom::mousePressEvent(QMouseEvent *event)
{
	emit evt_mousePressEvent(event);
}

void QWidgetCustom::mouseReleaseEvent(QMouseEvent *event)
{
	emit evt_mouseReleaseEvent(event);
}

void QWidgetCustom::mouseDoubleClickEvent(QMouseEvent *event)
{
	emit evt_mouseDoubleClickEvent(event);
}

void QWidgetCustom::mouseMoveEvent(QMouseEvent *event)
{
	emit evt_mouseMoveEvent(event);
}

void QWidgetCustom::wheelEvent(QWheelEvent *event)
{
	emit evt_wheelEvent(event);
}

void QWidgetCustom::keyPressEvent(QKeyEvent *event)
{
	emit evt_keyPressEvent(event);
}

void QWidgetCustom::keyReleaseEvent(QKeyEvent *event)
{
	emit evt_keyReleaseEvent(event);
}

void QWidgetCustom::focusInEvent(QFocusEvent *event)
{
	emit evt_focusInEvent(event);
}

void QWidgetCustom::focusOutEvent(QFocusEvent *event)
{
	emit evt_focusOutEvent(event);
}

void QWidgetCustom::enterEvent(QEvent *event)
{
	emit evt_enterEvent(event);
}

void QWidgetCustom::leaveEvent(QEvent *event)
{
	emit evt_leaveEvent(event);
}

void QWidgetCustom::moveEvent(QMoveEvent *event)
{
	emit evt_moveEvent(event);
}

void QWidgetCustom::closeEvent(QCloseEvent *event)
{
	emit evt_closeEvent(event);
}

void QWidgetCustom::dragEnterEvent(QDragEnterEvent *event)
{
	emit evt_dragEnterEvent(event);
}

void QWidgetCustom::dragMoveEvent(QDragMoveEvent *event)
{
	emit evt_dragMoveEvent(event);
}

void QWidgetCustom::dragLeaveEvent(QDragLeaveEvent *event)
{
	emit evt_dragLeaveEvent(event);
}

void QWidgetCustom::showEvent(QShowEvent *event)
{
	emit evt_showEvent(event);
}

void QWidgetCustom::hideEvent(QHideEvent *event)
{
	emit evt_hideEvent(event);
}

void QWidgetCustom::resizeEvent(QResizeEvent *event)
{
	emit evt_resizeEvent(event);
}

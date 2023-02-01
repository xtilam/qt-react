#include "QWidgetCustom.h"

QWidgetCustom::QWidgetCustom(QWidget *parent) : QWidget(parent)
{
    static QMap<QString, int> map = {
		{"onMousePress", Signals::signal_onMousePress},
		{"onMouseRelease", Signals::signal_onMouseRelease},
		{"onMouseDoubleClick", Signals::signal_onMouseDoubleClick},
		{"onMouseMove", Signals::signal_onMouseMove},
		{"onWheel", Signals::signal_onWheel},
		{"onKeyPress", Signals::signal_onKeyPress},
		{"onKeyRelease", Signals::signal_onKeyRelease},
		{"onEnter", Signals::signal_onEnter},
		{"onLeave", Signals::signal_onLeave},
		{"onMove", Signals::signal_onMove},
		{"onDragEnter", Signals::signal_onDragEnter},
		{"onDragMove", Signals::signal_onDragMove},
		{"onDragLeave", Signals::signal_onDragLeave},
		{"onResize", Signals::signal_onResize},
	};
    countConnection.setMap(&map);
}


void QWidgetCustom::mousePressEvent(QMouseEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onMousePress)) return;
    QOMouseEvent evt;
    emit onMousePress(evt.setEvt(event));
}

void QWidgetCustom::mouseReleaseEvent(QMouseEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onMouseRelease)) return;
    QOMouseEvent evt;
    emit onMouseRelease(evt.setEvt(event));
}

void QWidgetCustom::mouseDoubleClickEvent(QMouseEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onMouseDoubleClick)) return;
    QOMouseEvent evt;
    emit onMouseDoubleClick(evt.setEvt(event));
}

void QWidgetCustom::mouseMoveEvent(QMouseEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onMouseMove)) return;
    QOMouseEvent evt;
    emit onMouseMove(evt.setEvt(event));
}

void QWidgetCustom::wheelEvent(QWheelEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onWheel)) return;
	emit onWheel(event);
}

void QWidgetCustom::keyPressEvent(QKeyEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onKeyPress)) return;
	emit onKeyPress(event);
}

void QWidgetCustom::keyReleaseEvent(QKeyEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onKeyRelease)) return;
	emit onKeyRelease(event);
}

void QWidgetCustom::focusInEvent(QFocusEvent *event)
{
    emit onFocusChanged(true);
}

void QWidgetCustom::focusOutEvent(QFocusEvent *event)
{
    emit onFocusChanged(false);
}

void QWidgetCustom::enterEvent(QEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onEnter)) return;
	emit onEnter(event);
}

void QWidgetCustom::leaveEvent(QEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onLeave)) return;
	emit onLeave(event);
}

void QWidgetCustom::moveEvent(QMoveEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onMove)) return;
	emit onMove(event);
}

void QWidgetCustom::closeEvent(QCloseEvent *event)
{
    emit onClose();
}

void QWidgetCustom::dragEnterEvent(QDragEnterEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onDragEnter)) return;
	emit onDragEnter(event);
}

void QWidgetCustom::dragMoveEvent(QDragMoveEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onDragMove)) return;
	emit onDragMove(event);
}

void QWidgetCustom::dragLeaveEvent(QDragLeaveEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onDragLeave)) return;
	emit onDragLeave(event);
}

void QWidgetCustom::showEvent(QShowEvent *event)
{
    emit onShow();
}

void QWidgetCustom::hideEvent(QHideEvent *event)
{
    emit onHide();
}

void QWidgetCustom::resizeEvent(QResizeEvent *event)
{
	if(countConnection.isNotExistsConnection(signal_onResize)) return;
    QOResizeEvent evt;
    emit onResize(evt.setEvt(event));
}

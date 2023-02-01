#include "QWindowCustom.h"
#include <QDebug>
#include <QMetaMethod>

QWindowCustom::QWindowCustom(QWidget *parent) : QMainWindow(parent)
{
    static QMap<QString, int> map = {
         {"onMousePress", signal_onMousePress},
         {"onMouseRelease", signal_onMouseRelease},
         {"onMouseDoubleClick", signal_onMouseDoubleClick},
         {"onMouseMove", signal_onMouseMove},
         {"onKeyPress", signal_onKeyPress},
         {"onKeyRelease", signal_onKeyRelease},
         {"onResize", signal_onResize},
     };
    this->countConnection.setMap(&map);
}

void QWindowCustom::reset()
{
    countConnection.reset();
}

void QWindowCustom::mousePressEvent(QMouseEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onMousePress)) return;
	QOMouseEvent evt;
	emit onMousePress(evt.setEvt(event));
}

void QWindowCustom::mouseReleaseEvent(QMouseEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onMouseRelease)) return;
	QOMouseEvent evt;
	emit onMouseRelease(evt.setEvt(event));
}

void QWindowCustom::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onMouseDoubleClick)) return;
	QOMouseEvent evt;
	emit onMouseDoubleClick(evt.setEvt(event));
}

void QWindowCustom::mouseMoveEvent(QMouseEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onMouseMove)) return;
	QOMouseEvent evt;
	emit onMouseMove(evt.setEvt(event));
}

void QWindowCustom::keyPressEvent(QKeyEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onKeyPress)) return;
	emit onKeyPress(event);
}

void QWindowCustom::keyReleaseEvent(QKeyEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onKeyRelease)) return;
	emit onKeyRelease(event);
}

void QWindowCustom::focusInEvent(QFocusEvent *event)
{
    emit onFocusChange(true);
}

void QWindowCustom::focusOutEvent(QFocusEvent *event)
{
    emit onFocusChange(false);
}

void QWindowCustom::resizeEvent(QResizeEvent *event)
{
    if(countConnection.isNotExistsConnection(signal_onResize)) return;
    QOResizeEvent evt;
    emit onResize(evt.setEvt(event));
}

void QWindowCustom::closeEvent(QCloseEvent *event)
{
    emit onClose();
}

void QWindowCustom::showEvent(QShowEvent *event)
{
    emit onShow();
}

void QWindowCustom::hideEvent(QHideEvent *event)
{
    emit onHide();
}

void QWindowCustom::connectNotify(const QMetaMethod &signal)
{
    countConnection.onConnectSignal(signal);
}

void QWindowCustom::disconnectNotify(const QMetaMethod &signal)
{
    countConnection.onDisconnectSignal(signal);
}

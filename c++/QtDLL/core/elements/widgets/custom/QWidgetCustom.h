#ifndef QWIDGETCUSTOM_H
#define QWIDGETCUSTOM_H

#include <QWidget>
#include "CountConnection.h"

class QWidgetCustom : public QWidget
{
    Q_OBJECT
    CountConnection countConnection;
    enum Signals{
		signal_onMousePress,
		signal_onMouseRelease,
		signal_onMouseDoubleClick,
		signal_onMouseMove,
		signal_onWheel,
		signal_onKeyPress,
		signal_onKeyRelease,
		signal_onEnter,
		signal_onLeave,
		signal_onMove,
		signal_onDragEnter,
		signal_onDragMove,
		signal_onDragLeave,
		signal_onResize,
    };
public:
    explicit QWidgetCustom(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
signals:
    void onResize(QOResizeEvent *event);
    void onMousePress(QOMouseEvent *event);
    void onMouseRelease(QOMouseEvent *event);
    void onMouseDoubleClick(QOMouseEvent *event);
    void onMouseMove(QOMouseEvent *event);
	void onWheel(QWheelEvent *event);
	void onKeyPress(QKeyEvent *event);
	void onKeyRelease(QKeyEvent *event);
    void onFocusChanged(bool isFocus);
	void onEnter(QEvent *event);
	void onLeave(QEvent *event);
	void onMove(QMoveEvent *event);
	void onDragEnter(QDragEnterEvent *event);
	void onDragMove(QDragMoveEvent *event);
	void onDragLeave(QDragLeaveEvent *event);
    void onShow();
    void onHide();
    void onClose();

};

#endif // QWIDGETCUSTOM_H

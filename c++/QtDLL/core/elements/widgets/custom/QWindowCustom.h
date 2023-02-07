#ifndef QWINDOWCUSTOM_H
#define QWINDOWCUSTOM_H

#include <QMainWindow>
#include "CountConnection.h"

class QWindowCustom : public QMainWindow
{
	Q_OBJECT
public:
	explicit QWindowCustom(QWidget *parent = nullptr);
	// QWidget interface
	enum Signals
	{
		signal_onMousePress,
		signal_onMouseRelease,
		signal_onMouseDoubleClick,
		signal_onMouseMove,
		signal_onKeyPress,
		signal_onKeyRelease,
		signal_onResize,
	};
    void reset();
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseDoubleClickEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
	void focusInEvent(QFocusEvent *event) override;
	void focusOutEvent(QFocusEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
	void closeEvent(QCloseEvent *event) override;
	void showEvent(QShowEvent *event) override;
	void hideEvent(QHideEvent *event) override;
signals:
    void onMousePress(QOMouseEvent *event);
    void onMouseRelease(QOMouseEvent *event);
    void onMouseDoubleClick(QOMouseEvent *event);
    void onMouseMove(QOMouseEvent *event);
	void onKeyPress(QKeyEvent *event);
	void onKeyRelease(QKeyEvent *event);
	void onResize(QOResizeEvent *event);
    void onFocusChange(bool isFocus);
    void onShow();
    void onHide();
    void onClose();

	// QObject interface
protected:
	void connectNotify(const QMetaMethod &signal) override;
	void disconnectNotify(const QMetaMethod &signal) override;

private:
    CountConnection countConnection;
};

#endif // QWINDOWCUSTOM_H

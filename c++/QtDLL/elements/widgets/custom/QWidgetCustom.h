#ifndef QWIDGETCUSTOM_H
#define QWIDGETCUSTOM_H

#include <QWidget>

class QWidgetCustom : public QWidget
{
    Q_OBJECT
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
	void evt_mousePressEvent(QMouseEvent *event);
	void evt_mouseReleaseEvent(QMouseEvent *event);
	void evt_mouseDoubleClickEvent(QMouseEvent *event);
	void evt_mouseMoveEvent(QMouseEvent *event);
	void evt_wheelEvent(QWheelEvent *event);
	void evt_keyPressEvent(QKeyEvent *event);
	void evt_keyReleaseEvent(QKeyEvent *event);
	void evt_focusInEvent(QFocusEvent *event);
	void evt_focusOutEvent(QFocusEvent *event);
	void evt_enterEvent(QEvent *event);
	void evt_leaveEvent(QEvent *event);
	void evt_moveEvent(QMoveEvent *event);
	void evt_closeEvent(QCloseEvent *event);
	void evt_dragEnterEvent(QDragEnterEvent *event);
	void evt_dragMoveEvent(QDragMoveEvent *event);
	void evt_dragLeaveEvent(QDragLeaveEvent *event);
	void evt_showEvent(QShowEvent *event);
	void evt_hideEvent(QHideEvent *event);
    void evt_resizeEvent(QResizeEvent *event);
};

#endif // QWIDGETCUSTOM_H

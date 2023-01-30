#ifndef QWINDOWCUSTOM_H
#define QWINDOWCUSTOM_H

#include <QMainWindow>

class QWindowCustom : public QMainWindow
{
    Q_OBJECT
public:
    explicit QWindowCustom(QWidget * parent);

    // QWidget interface
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
	void evt_mousePressEvent(QMouseEvent *event);
	void evt_mouseReleaseEvent(QMouseEvent *event);
	void evt_mouseDoubleClickEvent(QMouseEvent *event);
	void evt_mouseMoveEvent(QMouseEvent *event);
	void evt_keyPressEvent(QKeyEvent *event);
	void evt_keyReleaseEvent(QKeyEvent *event);
	void evt_focusInEvent(QFocusEvent *event);
	void evt_focusOutEvent(QFocusEvent *event);
	void evt_resizeEvent(QResizeEvent *event);
	void evt_closeEvent(QCloseEvent *event);
	void evt_showEvent(QShowEvent *event);
	void evt_hideEvent(QHideEvent *event);
};

#endif // QWINDOWCUSTOM_H

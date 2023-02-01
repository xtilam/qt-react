#ifndef QTPUSHBUTTON_H
#define QTPUSHBUTTON_H

#include <QPushButton>

class QtPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QtPushButton(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
signals:
	void evt_mousePressEvent(QMouseEvent *event);
	void evt_mouseReleaseEvent(QMouseEvent *event);
	void evt_mouseMoveEvent(QMouseEvent *event);
	void evt_keyPressEvent(QKeyEvent *event);
	void evt_keyReleaseEvent(QKeyEvent *event);
	void evt_focusInEvent(QFocusEvent *event);
	void evt_focusOutEvent(QFocusEvent *event);	
};

#endif // QTPUSHBUTTON_H

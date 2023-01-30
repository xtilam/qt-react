#ifndef QTWINDOW_H
#define QTWINDOW_H

#include "BaseWidgetElement.h"
#include "custom/QWindowCustom.h"

class QtWindow : public BaseWidgetElement
{
    Q_OBJECT
public:
    explicit QtWindow(QObject *parent = nullptr);

    // QtElement interface
public:
    QWindowCustom * window;
    QString tagName() override;
    QWidget *getWidget() override;

    Q_PROPERTY(int x READ r_x WRITE w_x)
    int r_x();
    void w_x(int x);

    Q_PROPERTY(int y READ r_y WRITE w_y)
    int r_y();
    void w_y(int y);

    Q_PROPERTY(int width READ r_width WRITE w_width)
    int r_width();
    void w_width(int width);

    Q_PROPERTY(int height READ r_height WRITE w_height)
    int r_height();
    void w_height(int height);

    Q_PROPERTY(QString title READ r_title WRITE w_title)
    QString r_title();
    void w_title(QString title);

    Q_PROPERTY(bool show READ r_show WRITE w_show)
    bool r_show();
    void w_show(bool isShow);

public slots:
    void setAttribute(QString key, QString value) override;
    void removeAttribute(QString key) override;
    void insertBefore(QtElement *el, QtElement *beforeEl) override;
    void removeElement(QtElement *el) override;
};

#endif // QTWINDOW_H

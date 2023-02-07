#ifndef QTWINDOW_H
#define QTWINDOW_H

#include "BaseWidgetElement.h"
#include "custom/QWindowCustom.h"
#include "QtWidget.h"

class QtWindow : public BaseWidgetElement
{
    Q_OBJECT
public:
    explicit QtWindow(QObject *parent = nullptr);
    ~QtWindow();
    // QtElement interface
public:
    QWindowCustom * window;
    QString tagName() override;
    QWidget *getWidget() override;
    QtWidget * centralWidget;

    Q_PROPERTY(QString layout WRITE w_layout)
    void w_layout(QString layout);
    void reset();
public slots:
    void insertBefore(QtElement *el, QtElement *beforeEl) override;
    void removeChild(QtElement *el) override;
    void appendChild(QtElement *el) override;

    // QtElement interface
public:
    QWidget *getWidgetParentChild() override;
};

#endif // QTWINDOW_H

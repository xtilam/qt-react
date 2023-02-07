#ifndef QTWIDGET_H
#define QTWIDGET_H

#include <QWidget>
#include "BaseWidgetElement.h"
#include "../layouts/BaseLayout.h"
#include "custom/QWidgetCustom.h"

class QtWidget : public BaseWidgetElement
{
    Q_OBJECT
public:
    QList<QtElement *> widgetChild;
    BaseLayout * layout = nullptr;
    QWidgetCustom * widget;
    explicit QtWidget(QObject * parent = nullptr);
    Q_PROPERTY(QString layout WRITE w_layout READ r_layout)
    QString r_layout();
    void w_layout(QString layout);
    ~QtWidget();
public:
    QString tagName() override;
    QWidget *getWidget() override;
public slots:
    void insertBefore(QtElement *el, QtElement *beforeEl) override;
    void removeChild(QtElement *el) override;
    void appendChild(QtElement *el) override;
    void updateStyle() override;
};

#endif // QTWIDGET_H

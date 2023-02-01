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
    QString _layout;
    QList<BaseWidgetElement *> widgetChild;
    BaseLayout * layout;
    QWidgetCustom * widget;
    explicit QtWidget(QObject * parent = nullptr);
    Q_PROPERTY(QString layout WRITE w_layout)
    void w_layout(QString layout);
public:
    QString tagName() override;
    QWidget *getWidget() override;
public slots:
    void setAttribute(QString key, QString value) override;
    void removeAttribute(QString key) override;
    void insertBefore(QtElement *el, QtElement *beforeEl) override;
    void removeChild(QtElement *el) override;
};

#endif // QTWIDGET_H

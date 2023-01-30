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
public slots:

};

#endif // QTWIDGET_H

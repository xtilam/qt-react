#include "QtWidget.h"

QtWidget::QtWidget(QObject * parent) : BaseWidgetElement(parent)
{

}

void QtWidget::w_layout(QString layout)
{
//    typedef BaseLayout * (initLayoutAction)();
//    static std::initializer_list<initLayoutAction> initLayoutActions = {

//    };
}


QString QtWidget::tagName()
{
    return "qtwidget";
}

QWidget *QtWidget::getWidget()
{
}

void QtWidget::setAttribute(QString key, QString value)
{
}

void QtWidget::removeAttribute(QString key)
{
}

void QtWidget::insertBefore(QtElement *el, QtElement *beforeEl)
{
}

void QtWidget::removeChild(QtElement *el)
{
}

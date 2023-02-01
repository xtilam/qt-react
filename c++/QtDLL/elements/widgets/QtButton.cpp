#include "QtButton.h"

QtButton::QtButton(QObject *parent) : BaseWidgetElement(parent)
{
    this->button = new QtPushButton;
}

QtButton::~QtButton()
{
    delete this->button;
}


QString QtButton::tagName()
{
    return "qtbutton";
}

QWidget *QtButton::getWidget()
{
    return this->button;
}

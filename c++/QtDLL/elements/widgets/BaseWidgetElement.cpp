#include "BaseWidgetElement.h"

BaseWidgetElement::BaseWidgetElement(QObject *parent) : QtElement(parent)
{

}

QWidget *BaseWidgetElement::getWidget()
{
    return nullptr;
}


QString BaseWidgetElement::tagName()
{
    return "qt";
}

bool BaseWidgetElement::isWidget()
{
    return true;
}

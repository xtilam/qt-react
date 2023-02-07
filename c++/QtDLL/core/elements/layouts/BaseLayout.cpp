#include "BaseLayout.h"


BaseLayout::BaseLayout()
{

}

BaseLayout::~BaseLayout()
{

}

QLayout* BaseLayout::getLayout()
{
    return nullptr;
}

void BaseLayout::addWidget(BaseWidgetElement *widget)
{

}

void BaseLayout::insertBefore(BaseWidgetElement *widget, int index)
{

}

QString BaseLayout::layoutName()
{
    return "BASE_LAYOUT";
}

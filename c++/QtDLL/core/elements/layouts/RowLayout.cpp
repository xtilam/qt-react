#include "RowLayout.h"

RowLayout::RowLayout()
{
    this->layout = new QVBoxLayout;
    this->layout->setContentsMargins(0, 0, 0, 0);
}

RowLayout::~RowLayout()
{
    delete this->layout->parentWidget()->layout();
}

void RowLayout::addWidget(BaseWidgetElement *widget)
{
    this->layout->addWidget(widget->getWidget());
}

void RowLayout::insertBefore(BaseWidgetElement *widget, int index)
{
    this->layout->insertWidget(index, widget->getWidget());
}


QLayout *RowLayout::getLayout()
{
    return this->layout;
}


QString RowLayout::layoutName()
{
    return "row";
}

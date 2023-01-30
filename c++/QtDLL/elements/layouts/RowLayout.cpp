#include "RowLayout.h"


void RowLayout::addWidget(BaseWidgetElement *widget)
{
    this->layout->addWidget(widget->getWidget());
}

void RowLayout::insertBefore(BaseWidgetElement *widget, int index)
{
    this->layout->insertWidget(index, widget->getWidget());
}

void RowLayout::_delete()
{
    delete this->layout;
    delete this;
}

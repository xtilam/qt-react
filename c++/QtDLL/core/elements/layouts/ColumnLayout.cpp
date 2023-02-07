#include "ColumnLayout.h"

ColumnLayout::ColumnLayout()
{
    this->layout = new QHBoxLayout;
}

ColumnLayout::~ColumnLayout()
{
    delete this->layout;
}


QLayout *ColumnLayout::getLayout()
{
    return layout;
}

void ColumnLayout::addWidget(BaseWidgetElement *widget)
{
    this->layout->addWidget(widget->getWidget());
}

void ColumnLayout::insertBefore(BaseWidgetElement *widget, int index)
{
    this->layout->insertWidget(index, widget->getWidget());
}

QString ColumnLayout::layoutName()
{
    return "column";
}

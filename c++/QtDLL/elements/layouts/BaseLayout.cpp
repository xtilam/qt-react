#include "BaseLayout.h"
#include "RowLayout.h"



BaseLayout * initRowLayout(){ return new RowLayout; }

typedef BaseLayout * (*initLayoutAction)();
QMap<QString, initLayoutAction> mapInitLayout = {
    {"row", initRowLayout}
};

BaseLayout *BaseLayout::initLayout(QString layout)
{
    auto action = mapInitLayout[layout];
    if(!action) return action();
    return nullptr;
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

void BaseLayout::_delete()
{

}

#include "QtElementExtensions.h"
#include "elements/widgets/QtWindow.h"
#include "elements/widgets/QtWidget.h"
#include <QDebug>

QtElementExtensions::QtElementExtensions()
{

}


void QtElementExtensions::setupInit()
{
    std::initializer_list<initTagNameAction> actions = {
        [](){ return (QtElement *)new QtWindow; },
        [](){ return (QtElement *)new QtWidget; },
    };
    QtElement::addInitTagAction(actions);
}

void QtElementExtensions::setupEngine()
{

}

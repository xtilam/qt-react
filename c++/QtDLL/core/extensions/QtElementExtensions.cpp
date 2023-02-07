#include "QtElementExtensions.h"
#include "core/elements/widgets/QtWindow.h"
#include "core/elements/widgets/QtWidget.h"
#include "core/elements/widgets/QtButton.h"
#include "Utils.h"
#include <QDebug>

QtElementExtensions::QtElementExtensions()
{

}


void QtElementExtensions::setupInit()
{
    static std::initializer_list<QtElement::initTagNameAction> actions = {
        Utils::makeCallback<QtElement, QtWindow>(),
        Utils::makeCallback<QtElement, QtWidget>(),
        Utils::makeCallback<QtElement, QtButton>(),
    };
    QtElement::addInitTagAction(actions);
}

void QtElementExtensions::setupEngine()
{
//    QtElement::
}

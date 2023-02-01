#include "QtElementExtensions.h"
#include "elements/widgets/QtWindow.h"
#include "elements/widgets/QtWidget.h"
#include "elements/widgets/QtButton.h"
#include "Utils.h"
#include <QDebug>

QtElementExtensions::QtElementExtensions()
{

}


void QtElementExtensions::setupInit()
{
    static std::initializer_list<initTagNameAction> actions = {
        Utils::makeCallback<QtElement, QtWindow>(),
        Utils::makeCallback<QtElement, QtWidget>(),
        Utils::makeCallback<QtElement, QtButton>(),
    };
    QtElement::addInitTagAction(actions);
}

void QtElementExtensions::setupEngine()
{

}

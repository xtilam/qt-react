#include "BaseQObjectConvert.h"
#include <QDebug>

BaseQObjectConvert::BaseQObjectConvert(QObject * parent) : QObject(parent)
{
}

void BaseQObjectConvert::setupComplete()
{
    this->_isSetup = true;
}

bool BaseQObjectConvert::isSetup()
{
    return this->_isSetup;
}

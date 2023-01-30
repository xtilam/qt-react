#include "QtElement.h"

QtElement::QtElement(QObject * parent) : QObject(parent)
{

}

void QtElement::addInitTagAction(std::initializer_list<initTagNameAction> actions)
{
    for(const auto action: actions){
        auto el = action();
        listInitTag.insert(el->tagName(), action);
        delete el;
    }
}

QString QtElement::tagName()
{
    return "qt";
}

bool QtElement::isWidget()
{
    return false;
}

QWidget *QtElement::getWidget()
{
    return nullptr;
}

int QtElement::r_nodeType()
{
    return 1;
}

void QtElement::addEventListener(QJSValue name, QJSValue callback)
{

}

void QtElement::setAttribute(QString key, QString value)
{

}

void QtElement::removeAttribute(QString key)
{

}

QtElement *QtElement::createElement(QString tagName)
{
    auto action = listInitTag[tagName];
    if(action) return action();
    return nullptr;
}

void QtElement::insertBefore(QtElement *el, QtElement *beforeEl)
{

}

void QtElement::removeElement(QtElement *el)
{

}

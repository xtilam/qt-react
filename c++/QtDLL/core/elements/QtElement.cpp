#include "QtElement.h"
#include "COExports.h"
#include <QWidget>
#include <QStyle>

QObject *QtElement::r_ownerDocument()
{
    return this;
}

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

QWidget *QtElement::getWidgetParentChild()
{
    return this->getWidget();
}

QWidget *QtElement::getWidget()
{
    return nullptr;
}

QJSEngine *QtElement::engine()
{
    return objExport->app->engine();
}

QString QtElement::r_className()
{
    auto widget = getWidget();
    if(!widget) return this->metaObject()->className();
    return widget->property("class").toString();
}

void QtElement::w_className(QString className)
{
    auto widget = getWidget();
    if(!widget) return;
    widget->setProperty("class", className);
    updateStyle();
}

void QtElement::updateStyle()
{
    updateStyleWidget(getWidget());
}

void QtElement::updateStyleElement(QtElement *el)
{
    updateStyleWidget(el->getWidget());
}

void QtElement::updateStyleWidget(QWidget *widget)
{
    if(!widget) return;
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
}

int QtElement::r_nodeType()
{
    return 1;
}

void QtElement::addEventListener(QJSValue , QJSValue )
{

}

void QtElement::setAttribute(QString, QString)
{
}

void QtElement::removeAttribute(QString)
{

}

QObject *QtElement::createElement(QString tagName)
{
    auto action = listInitTag[tagName];
    if(action) {
        auto el = action();
        if(el->getWidget()){
            el->getWidget()->setParent(this->getWidgetParentChild());
        }
        return el;
    };
    objExport->app->engine()->throwError("cannot create element tag name: " + tagName);
    return nullptr;
}

QJSValue QtElement::createTextNode(QString text)
{
    return engine()->newQObject(new QtElement);
}

const QVariant QtElement::getProperty(QString property)
{
    return this->property(property.toStdString().c_str());
}

void QtElement::setProperty(QString property, const QVariant &value)
{
    QObject::setProperty(property.toStdString().c_str(), value);
}

void QtElement::updateCSS()
{

}

void QtElement::appendChild(QtElement *)
{

}

void QtElement::insertBefore(QtElement *, QtElement *)
{

}

void QtElement::removeChild(QtElement *)
{

}

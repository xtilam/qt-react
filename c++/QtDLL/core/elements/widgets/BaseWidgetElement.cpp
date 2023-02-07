#include "BaseWidgetElement.h"
#include <QDateTime>
#include <QStringList>
#include <QStringBuilder>
#include <thread>

BaseWidgetElement::BaseWidgetElement(QObject *parent) : QtElement(parent)
{

}

int BaseWidgetElement::r_x()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->x();
}

void BaseWidgetElement::w_x(int x)
{
    auto widget = getWidget();
    if(!widget) return;
    widget->move(x, widget->y());
}

int BaseWidgetElement::r_y()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->y();
}

void BaseWidgetElement::w_y(int y)
{

    auto widget = getWidget();
    if(!widget) return;
    widget->move(widget->x(), y);
}

int BaseWidgetElement::r_height()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->height();
}

void BaseWidgetElement::w_height(int height)
{
    auto widget = getWidget();
    if(!widget) return;
    widget->resize(widget->width(), height);
}

int BaseWidgetElement::r_width()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->width();
}

void BaseWidgetElement::w_width(int width)
{
    auto widget = getWidget();
    if(!widget) return;
    widget->resize(width, widget->height());
}

bool BaseWidgetElement::r_show()
{
    auto widget = getWidget();
    if(!widget) return false;
    return !widget->isHidden();
}

void BaseWidgetElement::w_show(bool isShow)
{
    auto widget = getWidget();
    if(!widget) return;
    isShow ? widget->show() : widget->hide();
}

bool BaseWidgetElement::r_disabled()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return !widget->isEnabled();
}

void BaseWidgetElement::w_disabled(bool isDisabled)
{
    auto widget = getWidget();
    if(!widget) return;
    isDisabled ? widget->setDisabled(true) : widget->setEnabled(true);
}

QString BaseWidgetElement::r_title()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->windowTitle();
}

void BaseWidgetElement::w_title(QString title)
{
    auto widget = getWidget();
    if(!widget) return;
    widget->setWindowTitle(title);
}

int BaseWidgetElement::r_windowFlags()
{
    auto widget = getWidget();
    if(!widget) return 0;
    return widget->windowFlags();
}

void BaseWidgetElement::w_windowFlags(int windowFlags)
{
    auto widget = getWidget();
    if(!widget) return;
    bool isShow = !widget->isHidden();
    widget->setWindowFlags((Qt::WindowFlags)windowFlags);
    if(isShow) widget->show();
}

int BaseWidgetElement::r_horPolicy()
{
    auto widget = getWidget();
    if(!widget) return -1;
    return (int) widget->sizePolicy().horizontalPolicy();
}

void BaseWidgetElement::w_horPolicy(int horPolicy)
{
    auto widget = getWidget();
    if(!widget) return;
    auto policy = widget->sizePolicy();
    policy.setHorizontalPolicy((QSizePolicy::Policy)horPolicy);
    widget->setSizePolicy(policy);
}

int BaseWidgetElement::r_verPolicy()
{
    auto widget = getWidget();
    if(!widget) return -1;
    return widget->sizePolicy().verticalPolicy();
}

void BaseWidgetElement::w_verPolicy(int verPolicy)
{
    auto widget = getWidget();
    if(!widget) return;
    auto policy = widget->sizePolicy();
    policy.setVerticalPolicy((QSizePolicy::Policy)verPolicy);
    widget->setSizePolicy(policy);
}

QJSValue BaseWidgetElement::r_css()
{
    auto widget = getWidget();
    if(!widget) return "";
    return widget->styleSheet();
}

void BaseWidgetElement::w_css(QJSValue style)
{
    static QMap<QString, QString> mapCssProperty;
    auto widget = getWidget();
    if(!widget) return;
    if(!style.isObject()) return widget->setStyleSheet("");
    auto map = style.toVariant().toMap();
    QString css;
    for(auto iter = map.begin(); iter != map.end(); iter++){
        auto property = mapCssProperty[iter.key()];
        if(property.length() == 0){
            auto str = iter.key().toStdString();
            int length = str.length();
            property = "";
            for(int i=0; i< length; i++){
                auto currentChar = str.at(i);
                if(currentChar >= 'A' && currentChar <= 'Z'){
                    property.append('-').append(currentChar + 32);
                }else{
                    property.append(currentChar);
                }
            }
        }
        css.append(property + ':' + iter.value().toString() + ";\n");
    }
    widget->setStyleSheet(css);
    qDebug() << css;
}


QString BaseWidgetElement::tagName()
{
    return "qt";
}

bool BaseWidgetElement::isWidget()
{
    return true;
}

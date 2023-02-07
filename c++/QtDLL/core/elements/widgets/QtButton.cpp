#include "QtButton.h"
#include "../QtElementSetAttributeAction.h"

QtButton::QtButton(QObject *parent) : BaseWidgetElement(parent)
{
    this->button = new QPushButton;
    this->button->setContentsMargins(0, 0, 0, 0);
}

QtButton::~QtButton()
{
    qDebug() << "button delete" << this;
    delete this->button;
}


QString QtButton::tagName()
{
    return "qtbutton";
}

QWidget *QtButton::getWidget()
{
    return this->button;
}

QString QtButton::r_text()
{
    return button->text();
}

void QtButton::w_text(QString text)
{
    button->setText(text);
}

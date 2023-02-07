#include "QtWindow.h"
#include "../QtElementSetAttributeAction.h"
#include <QStyle>

QtWindow::QtWindow(QObject *parent) : BaseWidgetElement(parent)
{
    this->window = new QWindowCustom;
    this->centralWidget = new QtWidget;
    this->window->hide();
    window->setCentralWidget(centralWidget->getWidget());
}

QtWindow::~QtWindow()
{
    delete this->window;
}


QString QtWindow::tagName()
{
    return "qtwindow";
}

QWidget *QtWindow::getWidget()
{
    return this->window;
}

void QtWindow::w_layout(QString layout)
{
    this->centralWidget->w_layout(layout);
}

void QtWindow::reset()
{
    delete this->centralWidget;
    this->centralWidget = new QtWidget;
    window->setCentralWidget(centralWidget->getWidget());
    this->window->setStyleSheet("");
    this->window->setProperty("class", "QtWindow");
    this->window->reset();
}

void QtWindow::insertBefore(QtElement *el, QtElement *beforeEl)
{
    this->centralWidget->insertBefore(el, beforeEl);
}

void QtWindow::removeChild(QtElement *el)
{
    this->centralWidget->removeChild(el);
}

void QtWindow::appendChild(QtElement *el)
{
    this->centralWidget->appendChild(el);
}


QWidget *QtWindow::getWidgetParentChild()
{
    return this->window->centralWidget();
}

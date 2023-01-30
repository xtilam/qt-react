#include "QtWindow.h"

QtWindow::QtWindow(QObject *parent) : BaseWidgetElement(parent)
{

}


QString QtWindow::tagName()
{
    return "qtwindow";
}

QWidget *QtWindow::getWidget()
{
    return this->window;
}

int QtWindow::r_x()
{
    return window->x();
}

void QtWindow::w_x(int x)
{
    window->move(x, window->y());
}

int QtWindow::r_y()
{
    return window->y();
}

void QtWindow::w_y(int y)
{
    window->move(window->y(), y);
}

int QtWindow::r_width()
{
    return window->width();
}

void QtWindow::w_width(int width)
{
    window->resize(width, window->height());
}

int QtWindow::r_height()
{
    return window->height();
}

void QtWindow::w_height(int height)
{
    window->resize(window->width(), height);
}

QString QtWindow::r_title()
{
    return window->windowTitle();
}

void QtWindow::w_title(QString title)
{
    window->setWindowTitle(title);
}

bool QtWindow::r_show()
{
    return !window->isHidden();
}

void QtWindow::w_show(bool isShow)
{
    isShow ? window->show() : window->hide();
}

void QtWindow::setAttribute(QString key, QString value)
{

}

void QtWindow::removeAttribute(QString key)
{
}

void QtWindow::insertBefore(QtElement *el, QtElement *beforeEl)
{

}

void QtWindow::removeElement(QtElement *el)
{

}

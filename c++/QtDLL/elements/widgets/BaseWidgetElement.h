#ifndef BASEWIDGETELEMENT_H
#define BASEWIDGETELEMENT_H

#include "../QtElement.h"
#include <QObject>

class BaseWidgetElement : public QtElement
{
public:
    explicit BaseWidgetElement(QObject *parent = nullptr);
    QWidget * getWidget();

public:
    QString tagName() override;
    bool isWidget() override final;
};

#endif // BASEWIDGETELEMENT_H

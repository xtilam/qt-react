#ifndef QTBUTTON_H
#define QTBUTTON_H

#include "BaseWidgetElement.h"
#include "custom/QtPushButton.h"

class QtButton : public BaseWidgetElement
{
    Q_OBJECT
public:
    QtPushButton * button;
    explicit QtButton(QObject *parent = nullptr);
    ~QtButton();
    // QtElement interface
public:
    QString tagName() override;
    QWidget *getWidget() override;
};

#endif // QTBUTTON_H

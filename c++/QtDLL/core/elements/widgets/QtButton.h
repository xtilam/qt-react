#ifndef QTBUTTON_H
#define QTBUTTON_H

#include "BaseWidgetElement.h"
#include <QPushButton>

class QtButton : public BaseWidgetElement
{
    Q_OBJECT
public:
    QPushButton * button;
    explicit QtButton(QObject *parent = nullptr);
    ~QtButton();
    // QtElement interface
public:
    QString tagName() override;
    QWidget *getWidget() override;

    Q_PROPERTY(QString text READ r_text WRITE w_text)
    QString r_text();
    void w_text(QString text);
};

#endif // QTBUTTON_H

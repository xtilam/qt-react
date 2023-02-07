#ifndef QTLINEEDIT_H
#define QTLINEEDIT_H

#include "BaseWidgetElement.h"
#include <QLineEdit>

class QtLineEdit : public BaseWidgetElement
{
    Q_OBJECT
public:
    QLineEdit * widget;
    explicit QtLineEdit(QObject *parent = nullptr);

    // QtElement interface
public:
    QString tagName() override;
    QWidget *getWidget() override;
};

#endif // QTLINEEDIT_H

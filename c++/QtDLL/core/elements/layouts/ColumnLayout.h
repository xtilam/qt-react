#ifndef COLUMLAYOUT_H
#define COLUMLAYOUT_H

#include "BaseLayout.h"
#include <QHBoxLayout>

class ColumnLayout : public BaseLayout
{
public:
    ColumnLayout();
public:
    QHBoxLayout * layout;
    ~ColumnLayout();
    QLayout *getLayout() override;
    void addWidget(BaseWidgetElement *widget) override;
    void insertBefore(BaseWidgetElement *widget, int index) override;
    QString layoutName() override;
};

#endif // COLUMLAYOUT_H

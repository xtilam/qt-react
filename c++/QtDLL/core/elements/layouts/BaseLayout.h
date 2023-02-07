#ifndef BASELAYOUT_H
#define BASELAYOUT_H

#include "../widgets/BaseWidgetElement.h"
#include <QLayout>

class BaseLayout
{
public:
    BaseLayout();
    virtual ~BaseLayout();
    virtual QLayout * getLayout();
    virtual void addWidget(BaseWidgetElement * widget);
    virtual void insertBefore(BaseWidgetElement * widget, int index);
    virtual QString layoutName();
};

#endif // BASELAYOUT_H

#ifndef BASELAYOUT_H
#define BASELAYOUT_H

#include "../widgets/BaseWidgetElement.h"
#include <QLayout>

class BaseLayout
{
public:
    BaseLayout * initLayout(QString layout);
    virtual QLayout * getLayout();
    virtual void addWidget(BaseWidgetElement * widget);
    virtual void insertBefore(BaseWidgetElement * widget, int index);
    virtual void _delete();
};

#endif // BASELAYOUT_H

#ifndef ROWLAYOUT_H
#define ROWLAYOUT_H

#include "BaseLayout.h"
#include <QHBoxLayout>

class RowLayout : public BaseLayout
{
public:
    QHBoxLayout * layout;
    void addWidget(BaseWidgetElement *widget) override;
    void insertBefore(BaseWidgetElement *widget, int index) override;
    void _delete() override;
};

#endif // ROWLAYOUT_H

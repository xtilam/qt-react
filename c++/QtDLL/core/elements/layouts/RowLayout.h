#ifndef ROWLAYOUT_H
#define ROWLAYOUT_H

#include "BaseLayout.h"
#include <QVBoxLayout>

class RowLayout : public BaseLayout
{
public:
    QVBoxLayout * layout;
    explicit RowLayout();
    ~RowLayout();
    void addWidget(BaseWidgetElement *widget) override;
    void insertBefore(BaseWidgetElement *widget, int index) override;
    QLayout *getLayout() override;
    QString layoutName() override;
};

#endif // ROWLAYOUT_H

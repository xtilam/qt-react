#ifndef QTELEMENTEXTENSIONS_H
#define QTELEMENTEXTENSIONS_H

#include "BaseExtension.h"

class QtElementExtensions : public BaseExtension
{
public:
    QtElementExtensions();
    // BaseExtension interface
public:
    void setupInit() override;
    void setupEngine() override;
};

#endif // QTELEMENTEXTENSIONS_H

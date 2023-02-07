#ifndef CDEBUGGER_H
#define CDEBUGGER_H

#include "BaseObject.h"
#include <QDebug>

class CDebugger: public BaseObject
{
public:
    explicit CDebugger();
    inline static bool isEnableDebug = false;
    void log(FunctionInput * param);
    void logVariant(CVariant * variant, QDebug &debug, const char * trace = "", bool isSpace = true);
    SPrototype * getPrototype() override;
};

#endif // CDEBUGGER_H

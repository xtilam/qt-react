#ifndef COBJECT_H
#define COBJECT_H
#include "BaseObject.h"
#include "CVariant.h"
#include <QMap>

class CObject: public BaseObject
{
public:
    int autoIndex = 0;
    QMap<wstring, CVariant *> map = {};

    explicit CObject();
    ~CObject();
    void notPrototypeExecute(wchar_t *key, FunctionInput *params) override;

    void get(FunctionInput * param);
    void set(FunctionInput * param);
    void deleteProperty(FunctionInput * param);

    CVariant * getProperty(wchar_t * key);
    void removeProperty(wchar_t * key);
    void setProperty(wchar_t * key, CVariant * value);


    SPrototype *getPrototype() override;
};

#endif // COBJECT_H

#ifndef UIOBJECT_H
#define UIOBJECT_H

#include "BaseObject.h"
#include <QMap>

class UIObject : public BaseObject
{
public:
    int methodId = 0;
    explicit UIObject();
    ~UIObject();
    QMap<wstring, UIObject *> map;
    UIObject *add(wchar_t * key);

public:
    void notPrototypeExecute(wchar_t *key, FunctionInput *params) override;
    void clear();
    void setMethodID(int id);
};

#endif // UIOBJECT_H

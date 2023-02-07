#ifndef CPARAMS_H
#define CPARAMS_H

#include <QString>
#include <oaidl.h>

class CArray;
class CObject;
struct BaseObject;
class CVariant;

class FunctionInput
{
    bool hasNextParam();
    VARIANT* nextVariant();
    int index = 0;
public:
    DISPPARAMS* params;
    VARIANT* result;

    FunctionInput(DISPPARAMS*, VARIANT*);

    FunctionInput * setIndex(int index);

    //getter
    FunctionInput * nextToWString(wchar_t **);
    FunctionInput * nextToQString(QString *);
    FunctionInput * nextToNumber(long double *);
    FunctionInput * nextToArray(CArray **);
    FunctionInput * nextToObject(CObject **);
	FunctionInput * nextToBool(bool *);
	FunctionInput * nextToCVariant(CVariant *);

    CVariant * nextToCVariant();
    const QString nextToQString();
    wchar_t * nextToWString();
    bool nextToBool();
    CObject * nextToObject();
    CArray * nextToArray();
    long double nextToNumber();
    void * nextToPointer();

    //set result
    FunctionInput * setResultString(wchar_t * str);
    FunctionInput * setResultQString(QString result);
    FunctionInput * setResultNumber(double result);
    FunctionInput * setResultObject(BaseObject *);
	FunctionInput * setResultBool(bool);
	FunctionInput * setResultCVariant(CVariant *);
    FunctionInput * resetIndex(int index = 0);
    int length();
};

#endif // CPARAMS_H

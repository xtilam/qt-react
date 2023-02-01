#ifndef BASEQOBJECTCONVERT_H
#define BASEQOBJECTCONVERT_H

#include <QObject>

class BaseQObjectConvert : public QObject
{
    Q_OBJECT 
    bool _isSetup = false;
public:
    explicit BaseQObjectConvert(QObject * parent = nullptr);
    void setupComplete();
    bool isSetup();
};

#endif // BASEQOBJECTCONVERT_H

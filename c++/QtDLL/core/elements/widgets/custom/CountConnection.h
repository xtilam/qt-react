#ifndef COUNTCONNECTION_H
#define COUNTCONNECTION_H

#include <QString>
#include <QMap>
#include <QMetaMethod>
#include "../events/QOMouseEvent.h"
#include "../events/QOResizeEvent.h"

class CountConnection
{
    unsigned char * signalCount;
    QMap<QString, int> * map;
public:

    void setMap(QMap<QString, int> * map);
    ~CountConnection();
    void reset();
    void onConnectSignal(const QMetaMethod &signal);
    void onDisconnectSignal(const QMetaMethod &signal);
    bool isNotExistsConnection(int signalIndex);
    int countConnection(int signalIndex);

};

#endif // COUNTCONNECTION_H

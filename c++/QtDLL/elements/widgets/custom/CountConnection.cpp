#include "CountConnection.h"
#include <QDebug>

void CountConnection::setMap(QMap<QString, int> *map)
{
    this->map = map;
    auto size = this->map->size();
    this->signalCount = new unsigned char[size];
    this->reset();
}

CountConnection::~CountConnection()
{
    delete []this->signalCount;
}

void CountConnection::reset()
{
    auto size = this->map->size();
    for(int i=0; i<size; i++){
        this->signalCount[i] = 0;
    }
}

void CountConnection::onConnectSignal(const QMetaMethod &signal)
{
    if(!map->contains(signal.name())) return;
    int index = map->value(signal.name());
    ++this->signalCount[index];
}

void CountConnection::onDisconnectSignal(const QMetaMethod &signal)
{
    if(!map->contains(signal.name())) return;
    int index = map->value(signal.name());
    --this->signalCount[index];
}

bool CountConnection::isNotExistsConnection(int signalIndex)
{
    return this->signalCount[signalIndex] == 0;
}

int CountConnection::countConnection(int signalIndex)
{
    return this->signalCount[signalIndex];
}

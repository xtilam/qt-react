#ifndef QOSIZE_H
#define QOSIZE_H

#include <QSize>
#include "BaseQObjectConvert.h"

class QOSize : public BaseQObjectConvert
{
    Q_OBJECT
private:

public:
    QSize *size;
    explicit QOSize(QObject *parent = nullptr);
    QOSize * setSize(QSize * size);
    QOSize * setSize(const QSize * size);
    Q_PROPERTY(int width READ width)
    int width();
    Q_PROPERTY(int height READ height)
    int height();
    Q_PROPERTY(int rheight READ rheight)
    int rheight();
    Q_PROPERTY(int rwidth READ rwidth)
    int rwidth();
public slots:
    bool isEmpty();
    bool isNull();
    bool isValid();
};

#endif // QOSIZE_H

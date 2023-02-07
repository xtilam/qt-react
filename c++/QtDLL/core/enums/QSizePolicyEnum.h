#ifndef QSIZEPOLICYENUM_H
#define QSIZEPOLICYENUM_H

#include <QObject>
#include <QSizePolicy>

class QSizePolicyEnum : public QObject
{
    Q_GADGET
public:
    inline explicit QSizePolicyEnum(QObject *parent = nullptr) : QObject(parent){};
    enum Policy{
		Fixed = QSizePolicy::Policy::Fixed,
        Minimum = QSizePolicy::Policy::Minimum,
        Maximum = QSizePolicy::Policy::Maximum,
        Preferred = QSizePolicy::Policy::Preferred,
        MinimumExpanding = QSizePolicy::Policy::MinimumExpanding,
        Expanding = QSizePolicy::Policy::Expanding,
        Ignored = QSizePolicy::Policy::Ignored,
    };
    Q_ENUM(Policy)
};

#endif // QSIZEPOLICYENUM_H

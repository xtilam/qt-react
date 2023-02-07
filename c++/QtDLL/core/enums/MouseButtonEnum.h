#ifndef MOUSEBUTTON_H
#define MOUSEBUTTON_H

#include <QObject>

class MouseButtonEnum : public QObject{
    Q_GADGET;
public:
	inline explicit MouseButtonEnum(QObject * parent = nullptr) : QObject(parent){};
    enum class EnumValue{
        Alls = Qt::AllButtons,
        Back = Qt::BackButton,
        Extra1 = Qt::ExtraButton1,
        Extra10 = Qt::ExtraButton10,
        Extra11 = Qt::ExtraButton11,
        Extra12 = Qt::ExtraButton12,
        Extra13 = Qt::ExtraButton13,
        Extra14 = Qt::ExtraButton14,
        Extra15 = Qt::ExtraButton15,
        Extra16 = Qt::ExtraButton16,
        Extra17 = Qt::ExtraButton17,
        Extra18 = Qt::ExtraButton18,
        Extra19 = Qt::ExtraButton19,
        Extra2 = Qt::ExtraButton2,
        Extra20 = Qt::ExtraButton20,
        Extra21 = Qt::ExtraButton21,
        Extra22 = Qt::ExtraButton22,
        Extra23 = Qt::ExtraButton23,
        Extra24 = Qt::ExtraButton24,
        Extra3 = Qt::ExtraButton3,
        Extra4 = Qt::ExtraButton4,
        Extra5 = Qt::ExtraButton5,
        Extra6 = Qt::ExtraButton6,
        Extra7 = Qt::ExtraButton7,
        Extra8 = Qt::ExtraButton8,
        Extra9 = Qt::ExtraButton9,
        Forward = Qt::ForwardButton,
        Left = Qt::LeftButton,
        Middle = Qt::MiddleButton,
        No = Qt::NoButton,
        Right = Qt::RightButton,
        Task = Qt::TaskButton,
        X1 = Qt::XButton1,
        X2 = Qt::XButton2,
    };
    Q_ENUM(EnumValue)
};

#endif // MOUSEBUTTON_H

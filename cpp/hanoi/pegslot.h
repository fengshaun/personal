#ifndef PEGSLOT_H
#define PEGSLOT_H

#include <QPointF>

class PegSlot
{
    public:
        PegSlot(QPointF);

        bool isOccupied() const;
        void setOccupied(bool);

        QPointF location() const;

    private:
        QPointF m_loc;
        bool m_occupied;
};

#endif // PEGSLOT_H

#include "pegslot.h"

PegSlot::PegSlot(QPointF loc)
{
    m_loc = loc;
    m_occupied = false;
}

bool PegSlot::isOccupied() const {
    return m_occupied;
}

void PegSlot::setOccupied(bool yes) {
    m_occupied = yes;
}

QPointF PegSlot::location() const {
    return m_loc;
}

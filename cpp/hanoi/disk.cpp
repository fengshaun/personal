#include <iostream>

#include "disk.h"
#include "peg.h"
#include "scene.h"

Disk::Disk(int size)
{
    m_size = size;
    m_roundness = 30;

    m_rect = new QRectF(-(width() / 2), -10, width(), 20);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    m_peg = 0;
}

void Disk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {
    painter->setBrush(Qt::darkGreen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundRect(*m_rect, m_roundness, m_roundness);
}

QRectF Disk::boundingRect() const {
    return *m_rect;
}

int Disk::width() {
    return (m_size+1) * 20;
}

int Disk::size() const {
    return m_size;
}

QPointF Disk::pos() const {
    return QGraphicsItem::pos();
}

Peg *Disk::currentPeg() const {
    return m_peg;
}

void Disk::setCurrentPeg(Peg *peg, Status stat) {
    if (stat == Moved) {
        Disk *disk = peg->topDisk();

        if (disk) {
            if (this->size() > disk->size()) {
                setPos(m_peg->lastOccupiedSlot()->location());
                return;
            }
        }
    }

    if (m_peg) {
        if (*m_peg == *peg) {
            setPos(m_peg->lastOccupiedSlot()->location());
            return;
        }
        m_peg->lastOccupiedSlot()->setOccupied(true);
    }
    if (stat == Moved) {
        m_peg->removeTopDisk();
    }
    m_peg = peg;
    setPos(peg->nextAvailableSlot()->location());
    peg->nextAvailableSlot()->setOccupied(true);
    peg->addDisk(this);    
}

bool Disk::operator==(const Disk &d) const {
    return m_size == d.size();
}

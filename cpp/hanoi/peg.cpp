#include <iostream>

#include "peg.h"

Peg::Peg(double w, double h, double left, double top, int id)
{
    m_id = id;
    m_width = w;
    m_height = h;
    m_rect = new QRectF(left, top, m_width, m_height);

    setZValue(-1);

    createSlots();
}

Peg::~Peg() {}

QRectF Peg::boundingRect() const {
    return *m_rect;
}

void Peg::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPointF left = m_rect->center() - QPointF(10, 0);
    QPointF top = m_rect->center() + QPointF(0, -80);
    QPointF topLeft = QPoint(left.x(), top.y());

    QSizeF size = QSizeF(20, int(m_rect->size().height() * 2/3));

    QRectF rect = QRectF(topLeft, size);

    painter->setBrush(Qt::darkRed);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(rect);
}

void Peg::addDisk(Disk *disk) {
    diskList.append(disk);
    disk->setCurrentPeg(this);
}

void Peg::removeTopDisk() {
    if (diskList.isEmpty()) {
        return;
    }

    Disk *disk = diskList.last();
    if (!disk) {
        disk = diskList.first();
    }

    diskList.pop_back();
    lastOccupiedSlot()->setOccupied(false);
}

void Peg::removeDisk(Disk *disk) {
    if (diskList.isEmpty()) {
        return;
    }

    int i = 0;
    for (i = 0; i < diskList.count(); i++) {
        if (*disk == *(diskList[i])) {
            //delete diskList[i];
            diskList.removeAt(i);
            m_slots[i]->setOccupied(false);
            break;
        }
    }
}

void Peg::removeDisks() {
    //deleting the disks
    for (int i = 0; i < diskList.count(); i++) {
        //delete diskList[i];
    }

    //set all the slots unoccupied
    for (int i = 0; i < 10; i++) {
        m_slots[i]->setOccupied(false);
    }

    diskList.clear();
}

PegSlot *Peg::nextAvailableSlot() {
    for (int i = 0; i < 10; i++) {
        if (!m_slots[i]->isOccupied()) {
            return m_slots[i];
        }
    }
}

PegSlot *Peg::lastOccupiedSlot() {
    if (m_slots[9]->isOccupied()) {
        return m_slots[9];
    }

    for (int i = 0; i < 10; i++) {
        if (!m_slots[i]->isOccupied()) {
            return m_slots[i-1];
        }
    }
}

void Peg::createSlots() {
    PegSlot *ps = new PegSlot(QPointF(m_rect->right() - m_rect->width() / 2, m_rect->height() - 15));
    m_slots.push_back(ps);

    for (int i = 0; i < 10; i++) {
        ps = new PegSlot(m_slots[i]->location() - QPointF(0, 25));
        m_slots.push_back(ps);
    }
}

bool Peg::operator==(const Peg &other) const {
    return m_id == other.id();
}

int Peg::id() const {
    return m_id;
}

Disk *Peg::topDisk() const {
    if (!diskList.isEmpty()) {
        return diskList.last();
    }
    return 0;
}

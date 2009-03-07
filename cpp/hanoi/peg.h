#ifndef PEG_H
#define PEG_H

#include <QGraphicsItem>
#include <QGraphicsSceneDragDropEvent>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QRect>
#include <QList>
#include <QVector>

#include "disk.h"
#include "pegslot.h"

class Peg : public QGraphicsItem
{
    public:
        Peg(double, double, double = 0, double = 0, int = 1);
        virtual ~Peg();

        virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        virtual QRectF boundingRect() const;

        void addDisk(Disk *);
        void removeTopDisk();
        void removeDisk(Disk *);
        void removeDisks();
        Disk *lastMovedDisk() const;
        PegSlot *nextAvailableSlot();
        PegSlot *lastOccupiedSlot();
        Disk *topDisk() const;

        int id() const;

        bool operator==(const Peg &) const;

    private:
        void createSlots();

        QRectF *m_rect;
        QList<Disk *> diskList;
        QList<PegSlot *> m_slots;
        Disk *m_lastMovedDisk;


        double m_width;
        double m_height;
        int m_id;
};

#endif // PEG_H

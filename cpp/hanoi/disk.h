#ifndef DISK_H
#define DISK_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QWidget>

class Peg;

class Disk : public QGraphicsItem
{
    public:
        Disk(int);

        enum Status { Static, Moved };

        void paint(QPainter *, const QStyleOptionGraphicsItem * const, QWidget *);
        QRectF boundingRect() const;

        int width();
        int size() const;
        Peg *currentPeg() const;
        void setCurrentPeg(Peg *, Status = Static);
        virtual QPointF pos() const;

        bool operator==(const Disk &) const;

    private:
        int m_size;
        int m_roundness;

        Peg *m_peg;

        QRectF *m_rect;
};

#endif // DISK_H

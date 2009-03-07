#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Peg;
class Disk;

class Scene : public QGraphicsScene
{
    Q_OBJECT

    public:
        Scene(double = 0, double = 0, double = 600, double = 500, QObject * = 0);

    public slots:
        void addNewDisk(int);
        void startNewGame(int);
        void removeLastDisk();
        void removeAllDisks();

    protected:
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *);

    private:
        Disk *selectedDisk();
        void refreshPegs();
        void setupPegs();

        Peg *m_firstPeg;
        Peg *m_secondPeg;
        Peg *m_thirdPeg;

        QList<Disk *> diskList;
};

#endif // SCENE_H

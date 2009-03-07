#include <iostream>

#include "scene.h"
#include "peg.h"
#include "disk.h"

Scene::Scene(double x, double y, double w, double h, QObject *parent)
        : QGraphicsScene(x, y, w, h, parent)
{
    setupPegs();
}

void Scene::setupPegs() {
    //last argument for pegs is the ID for comparison!
    m_firstPeg = new Peg(width() / 3, height(), 0, 0, 1);
    m_secondPeg = new Peg(width() / 3, height(), (width() / 3) + 1, 0, 2);
    m_thirdPeg = new Peg(width() / 3, height(), (width() * 2/3) + 1, 0, 3);

    addItem(m_firstPeg);
    addItem(m_secondPeg);
    addItem(m_thirdPeg);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_firstPeg->boundingRect().contains(event->scenePos())) {
        Disk *disk = selectedDisk();
        if (disk) {
            disk->setCurrentPeg(m_firstPeg, Disk::Moved);
        }
    } else if (m_secondPeg->boundingRect().contains(event->scenePos())) {
        Disk *disk = selectedDisk();
        if (disk) {
            disk->setCurrentPeg(m_secondPeg, Disk::Moved);
        }
    } else if (m_thirdPeg->boundingRect().contains(event->scenePos())) {
        Disk *disk = selectedDisk();
        if (disk) {
            disk->setCurrentPeg(m_thirdPeg, Disk::Moved);
        }
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

Disk *Scene::selectedDisk() {
    QList<QGraphicsItem *> items = selectedItems();
    if (items.count() == 1) {
        return dynamic_cast<Disk *>(items.first());
    }
    return 0;
}

void Scene::addNewDisk(int num) {
    if (num > 10 || num < 1) {
        return;
    }

    Disk *disk = new Disk(num);
    diskList.append(disk);
    addItem(disk);
    m_firstPeg->addDisk(disk);
}

void Scene::startNewGame(int level) {
    //deleting all the remaining disks
    removeAllDisks();
    diskList.clear();

    for (int i = level; i > 0; i--) {
        addNewDisk(i);
    }
}

void Scene::removeLastDisk() {
    if (diskList.isEmpty()) {
        return;
    }
    Disk *disk = diskList.last();
    disk->currentPeg()->removeDisk(disk);
    diskList.pop_back();
}

void Scene::removeAllDisks() {
    m_firstPeg->removeDisks();
    m_secondPeg->removeDisks();
    m_thirdPeg->removeDisks();

    for (int i = 0; i < diskList.count(); i++) {
        delete diskList[i];
    }

    diskList.clear();
}

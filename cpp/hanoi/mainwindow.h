#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QAction>
#include <QList>
#include <QSpinBox>
#include <QMenu>
#include <QMenuBar>

#include "ui_mainwindow.h"
#include "disk.h"
#include "peg.h"
#include "scene.h"

class MainWindow : public QMainWindow, private Ui::MainWindowClass
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        void setupActions();
        void setupToolbar();
        void setupMenu();

    protected slots:
        void newGame();

    private:
        QGraphicsView *view;
        Scene *scene;

        QAction *m_newGameAction;
        QSpinBox *m_levelSpinBox;
        QMenu *m_fileMenu;
};

#endif // MAINWINDOW_H

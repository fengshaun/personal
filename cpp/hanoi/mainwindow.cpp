#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    view = new QGraphicsView;
    scene = new Scene;
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(Qt::white);
    setCentralWidget(view);
    resize(610, 540);

    m_levelSpinBox = new QSpinBox;
    m_levelSpinBox->setMinimum(1);
    m_levelSpinBox->setMaximum(10);

    setupActions();
    setupToolbar();

    connect(m_newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));
}

MainWindow::~MainWindow() {
}

void MainWindow::setupActions() {
    m_newGameAction = new QAction("Add", this);
}

void MainWindow::setupToolbar() {
    m_toolbar->addAction(m_newGameAction);
    m_toolbar->addWidget(m_levelSpinBox);
}

void MainWindow::setupMenu() {
    m_fileMenu = new QMenu(tr("&File"));
    m_fileMenu->addAction(m_newGameAction);
    menuBar()->addMenu(m_fileMenu);
}


void MainWindow::newGame() {
    scene->startNewGame(m_levelSpinBox->value());
}

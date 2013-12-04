#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("DSA1 Savegame-Editor");
    createInterface();
    createActions();
    createMenu();
    setMinimumSize(800, 600);
}

MainWindow::~MainWindow() {

}

void MainWindow::createInterface() {

    centralWidget = new QWidget(this);
    gridLayout = new QGridLayout(centralWidget);

    setCentralWidget(centralWidget);
}

void MainWindow::createMenu() {

    fileMenu = menuBar()->addMenu(tr("&Datei"));
    fileMenu->addAction(openFileAction);

    editMenu = menuBar()->addMenu(tr("&Bearbeiten"));
    aboutMenu = menuBar()->addMenu(tr("&Info"));
}

void MainWindow::createActions() {

    openFileAction = new QAction(tr(QString::fromUtf8("Öffnen").toStdString().c_str()), this);
    openFileAction->setStatusTip(tr("Einen Spielstand laden"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(onOpenFileAction()));
}


void MainWindow::onOpenFileAction() {

    QString filename = QFileDialog::getOpenFileName(this, tr("Spielstand laden"), "", tr("DSA1-Dateiformat (*.GAM)"));
}

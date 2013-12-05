#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QLabel>
#include <QtGui/QGridLayout>
#include <QtGui/QFileDialog>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include "savegame.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onOpenFileAction();

private:
    void createInterface();
    void createMenu();
    void createActions();

    QWidget *centralWidget;
    QGridLayout *gridLayout;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *aboutMenu;

    QAction *openFileAction;
    QAction *saveFileAction;

    SaveGame saveGame;
};

#endif

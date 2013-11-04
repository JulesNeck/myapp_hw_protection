
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QstWGT>
#include <QStringList>
#include <QstIGS>

#include "demo.h"
#include "training.h"
#include "royalty.h"
#include "help.h"


QT_BEGIN_NAMESPACE
                class QAction;
                class QMenu;
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
     void tACT();

    void origSize();

    void showTraining();
    void showLicense();

    void showHelp();

private:
     Demo *demoArea;
     Training *trAA;
     Royalty *royaltyArea;
     Help *helpArea;

     QstWGT *stWGT;
     QMenu *windowMenu;
     QMenu *switchtoMenu;
     QMenu *helpMenu;

     QAction *minSizeAct;
     QAction *origSizeAct;
     QAction *fullSizeAct;
     QAction *exitAct;

     QAction *shTAAN;
     QAction *shLINAN;

     QAction *showHelpAct;

     void createActions();
     void createMenus();

     void reSTG();
     void wrSTG();

     void sCK();
     void rCHK();

     bool iCNST();
     bool iSTTM();
     bool iVLD();

};

#endif // MAINWINDOW_H




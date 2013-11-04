#include "mainwindow.h"


MainWindow::MainWindow()
{
      royaltyArea = new Royalty(this);
      demoArea = new Demo(this);
      helpArea = new Help(this);

      stWGT = new QstWGT;

      stWGT->addWidget(royaltyArea);
      stWGT->addWidget(demoArea);
      stWGT->addWidget(helpArea);
      setCentralWidget(stWGT);

      sCK();

      stWGT->setCurrentIndex(1);

      reSTG();

      setWindowTitle(tr("MyApp"));
      setMinimumSize(800, 600);
      setUnifiedTitleAndToolBarOnMac(true);

      createActions();
      createMenus();
}



void MainWindow::sCK()
{
    if (royaltyArea->iFSST()) {
        royaltyArea->iNSTM();
    } else {
        rCHK();
    }
}



void MainWindow::rCHK() {

    if ( iCNST()  &&  iSTTM()   &&   iVLD() )
    {
        trAA = new Training(this);
        stWGT->removeWidget(demoArea);
        stWGT->insertWidget(1, trAA);

        royaltyArea->ui->toCBPushButton->setEnabled(false);
        royaltyArea->ui->fromCBPushButton->setEnabled(false);
        royaltyArea->ui->royaltyPushButton->setEnabled(false);
        royaltyArea->ui->fcLineEdit->setText("message text");
        royaltyArea->ui->rcLineEdit->setEnabled(false);
        royaltyArea->ui->fcLineEdit->setEnabled(false);
    }
}



bool MainWindow::iCNST()
{
      QstIGS stIGS("ExampleCompany", "MyApp");

      QString alDATST;
      for (int x = 0; x < 10; ++x)
      {
            alDATST += stIGS.value(QString("dns%1").arg(x)).toString() + "-" ;
      }

      QStringList dtsSRLS  = alDATST.split("-" , QString::SkipEmptyParts);

      QList<qulonglong> dsNMBS;
      bool ok;
      for (int x = 0; x < dtsSRLS.size(); ++x)
      {
        dsNMBS <<  dtsSRLS.at(x).toULongLong(&ok, 10);
      }

      bool isOk;

      isOk = (dsNMBS.at(5) == royaltyArea->cks(  dsNMBS.mid(0, 5) ) )
           &&   (dsNMBS.at(11) == royaltyArea->cks(  dsNMBS.mid(6, 5) ) )
           &&   (dsNMBS.at(17) == royaltyArea->cks(  dsNMBS.mid(12, 5) ) )
           &&   (dsNMBS.at(23) == royaltyArea->cks(  dsNMBS.mid(18, 5) ) )
           &&   (dsNMBS.at(29) == royaltyArea->cks(  dsNMBS.mid(24, 5) ) )
           &&   (dsNMBS.at(35) == royaltyArea->cks(  dsNMBS.mid(30, 5) ) )
           &&   (dsNMBS.at(41) == royaltyArea->cks(  dsNMBS.mid(36, 5) ) )
           &&   (dsNMBS.at(47) == royaltyArea->cks(  dsNMBS.mid(42, 5) ) )
           &&   (dsNMBS.at(53) == royaltyArea->cks(  dsNMBS.mid(48, 5) ) )
           &&   (dsNMBS.at(59) == royaltyArea->cks(  dsNMBS.mid(54, 5) ) );

     return isOk;
}



bool MainWindow::iSTTM()
{
      QstIGS stIGS("ExampleCompany", "MyApp");

      QString saDSSKY = stIGS.value("dns8").toString();
      saDSSKY = royaltyArea->deSYKY( saDSSKY );

      QString crrSK = royaltyArea->geSKY();

      int dCNT = 0;

      if (  saDSSKY.mid(0, 6) != crrSK.mid(0 ,6)  )
            ++ dCNT;

      if (  saDSSKY.mid(7, 6) != crrSK.mid(7, 6)  )
            ++ dCNT;

      if (  saDSSKY.mid(14, 6) != crrSK.mid(14, 6)  )
            ++ dCNT;

      if (  saDSSKY.mid(21, 6) != crrSK.mid(21, 6)  )
            ++ dCNT;

      if (  saDSSKY.mid(28,6) != crrSK.mid(28,6)  )
            ++ dCNT;

      return dCNT < 2;
}




bool MainWindow::iVLD()
{
      QstIGS stIGS("ExampleCompany", "MyApp");

      QString saATKY = stIGS.value("dns6").toString();
      saATKY = royaltyArea->deACKY( saATKY );

      QString crAK = royaltyArea->geAKY(  royaltyArea->geSKY()  );

      int dCNT = 0;

      if (  saATKY.mid(0, 6) != crAK.mid(0 ,6)  )
            ++ dCNT;

      if (  saATKY.mid(7, 6) != crAK.mid(7, 6)  )
            ++ dCNT;

      if (  saATKY.mid(14, 6) != crAK.mid(14, 6)  )
            ++ dCNT;

      if (  saATKY.mid(21, 6) != crAK.mid(21, 6)  )
            ++ dCNT;

      if (  saATKY.mid(28,6) != crAK.mid(28,6)  )
            ++ dCNT;

      return dCNT < 2;

}



 void MainWindow::tACT() {

             if (  (royaltyArea->cACK() == true)  &&  iCNST()   )
                   {
                     QString wrtSKY = royaltyArea->enSYKY( royaltyArea->geSKY () );
                     QString wrtAKKY = royaltyArea->enACKY( royaltyArea->geAKY (  royaltyArea->geSKY ()  ) );

                     QstIGS stIGS("Example Company", "MyApp");
                     stIGS.setValue(QString("dns8"), wrtSKY);
                     stIGS.setValue(QString("dns6"), wrtAKKY);

                     trAA = new Training(this);
                     stWGT->removeWidget(demoArea);
                     stWGT->insertWidget(1, trAA);

                     royaltyArea->ui->toCBPushButton->setEnabled(false);
                     royaltyArea->ui->fromCBPushButton->setEnabled(false);
                     royaltyArea->ui->royaltyPushButton->setEnabled(false);
                     royaltyArea->ui->fcLineEdit->setText("message text");
                     royaltyArea->ui->rcLineEdit->setEnabled(false);
                     royaltyArea->ui->fcLineEdit->setEnabled(false);
                   }
             else
                   {
                     if  ( ! iCNST() )
                     {
                        royaltyArea-> ui->fcLineEdit->setText("emessage 1");
                     } else {
                        royaltyArea-> ui->fcLineEdit->setText("emessage 2");
                     }
                   }
}



void MainWindow::showTraining()  { stWGT->setCurrentIndex(1); stWGT->setFocus(); }
void MainWindow::showLicense()   { stWGT->setCurrentIndex(0); stWGT->setFocus(); }
void MainWindow::showHelp()      { stWGT->setCurrentIndex(2); stWGT->setFocus(); }



void MainWindow::createActions()
{
      connect(royaltyArea->ui->royaltyPushButton, SIGNAL(clicked()), SLOT(tACT()));

      minSizeAct = new QAction(QIcon(""), tr("&min"), this);
      minSizeAct->setShortcut(tr("Ctrl+M"));
      connect(minSizeAct, SIGNAL(triggered()), this, SLOT(showMinimized()));

      origSizeAct = new QAction(QIcon(""), tr("&stan"), this);
      origSizeAct->setShortcut(tr("Ctrl+S"));
      connect(origSizeAct, SIGNAL(triggered()), this, SLOT(showNormal()));
      connect(origSizeAct, SIGNAL(triggered()), this, SLOT(origSize()));

      fullSizeAct = new QAction(QIcon(""), tr("&voll"), this);
      fullSizeAct->setShortcut(tr("Ctrl+F"));
      connect(fullSizeAct, SIGNAL(triggered()), this, SLOT(showMaximized()));

      exitAct = new QAction(QIcon(""), tr("&quit"), this);
      exitAct->setShortcut(tr("Ctrl+Q"));
      connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

      shTAAN = new QAction(QIcon(""), tr("&train"), this);
      shTAAN->setShortcut(tr("Ctrl+T"));
      connect(shTAAN, SIGNAL(triggered()), this, SLOT(showTraining()));

      shLINAN = new QAction(QIcon(""), tr("&lic"), this);
      shLINAN->setShortcut(tr("Ctrl+A"));
      connect(shLINAN, SIGNAL(triggered()), this, SLOT(showLicense()));

      showHelpAct = new QAction(QIcon(""), tr("help"), this);
      showHelpAct->setShortcut(tr("F1"));
      connect(showHelpAct, SIGNAL(triggered()), this, SLOT(showHelp()));
}



void MainWindow::createMenus()
{
      windowMenu = menuBar()->addMenu(tr("win"));
      windowMenu->addAction(fullSizeAct);
      windowMenu->addAction(origSizeAct);
      windowMenu->addAction(minSizeAct);

      windowMenu->addSeparator();
      windowMenu->addAction(printAct);
      windowMenu->addSeparator();
      windowMenu->addAction(exitAct);

      switchtoMenu = menuBar()->addMenu(tr("to"));
      switchtoMenu->addAction(shTAAN);
      switchtoMenu->addSeparator();
      switchtoMenu->addAction(shLINAN);

      helpMenu = menuBar()->addMenu(tr("help"));
      helpMenu->addAction(showHelpAct);
}



void MainWindow::closeEvent(QCloseEvent *event)
{
      wrSTG();
      event->accept();
}



void MainWindow::reSTG()
{
    QstIGS stIGS("ExampleCompany", "MyApp");
    QPoint pos = stIGS.value("pos", QPoint(100, 100)).toPoint();
    QSize size = stIGS.value("size", QSize(1024, 768)).toSize();
    move(pos);
    resize(size);
}



void MainWindow::wrSTG()
{
    QstIGS stIGS("ExampleCompany", "MyApp");
    stIGS.setValue("pos", pos());
    stIGS.setValue("size", size());
}



void MainWindow::origSize()
{
    setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        QSize(1024, 768),
        qApp->desktop()->availableGeometry()
    ));
}


#ifndef ROYALTY_H
#define ROYALTY_H

#include <QNetworkInterface>
#include "ui_Royalty.h"


namespace Ui {
    class Royalty;
}

class Royalty : public QWidget
{
    Q_OBJECT

public:
      explicit Royalty(QWidget *parent = 0);
      ~Royalty();

      QList <qulonglong> cNUMAX();
      qulonglong cks(QList <qulonglong>);
      QList <qulonglong> gSN();
      QList <qulonglong> cSK(QList <qulonglong>);
      QString geSKY();
      QString geAKY(QString);

      bool cACK();
      bool ckVLD();

      bool iFSST();
      void iNSTM();
      void aNSRT();

      QString enSYKY(QString);
      QString deSYKY(QString);
      QString enACKY(QString);
      QString deACKY(QString);

      QStringList hwDSTL;

      bool iNMMA();
      bool iSTTMOK();
      bool iNMCDOK();

      Ui::Royalty *ui;


private:
    QString strOutput1, strOutput2, strOutput3, strOutput4, strOutput5, strOutput6, strOutput7, strOutput8;
    QList<qulonglong> orderedList;


private slots:
    void tCbo();
    void fCbo();


};

#endif // ROYALTY_H

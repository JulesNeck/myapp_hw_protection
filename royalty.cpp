#include "royalty.h"
#include "mainwindow.h"




Royalty::Royalty(QWidget *parent) : QWidget(parent), ui(new Ui::Royalty)
{
      ui->setupUi(this);
      connect(ui->toCBPushButton, SIGNAL(clicked()), SLOT(tCbo()));
      connect(ui->fromCBPushButton, SIGNAL(clicked()), SLOT(fCbo()));
      ui->rcLineEdit->setText( geSKY() );
}



qulonglong Royalty::cks (QList <qulonglong> fvNUR)
{
      int cryNUber = 48652;

      quint32 cks = 0;
      int lwLMT = 3765432;
      int urLMT = 8765439;

      for (int x = 0; x < fvNUR.size(); ++x) {

          QString tempStr = QString::number(fvNUR[x]);

          for (int y = 0; y < tempStr.length(); ++y) {
            cks += cryNUber * (    (tempStr.mid(y, 1).toInt() + 1) * (tempStr.mid(y, 1).toInt() + 1)    ) ;
          }
      }

      cks %= (urLMT - lwLMT) ;
      cks += lwLMT;

      return cks;
}



QString Royalty::enSYKY(QString sysKey) {

      QstIGS stIGS("ExampleCompany", "MyApp");

      int cryNU1 = (stIGS.value("dsn5").toString().mid(9, 8)).toInt();
      int cryNU2 = (stIGS.value("dsn3").toString().mid(36, 8)).toInt();
      int cryNU3 = (stIGS.value("dsn2").toString().mid(18, 8)).toInt();
      int cryNU4 = (stIGS.value("dsn1").toString().mid(27, 8)).toInt();
      int cryNU5 = (stIGS.value("dsn4").toString().mid(18, 8)).toInt();

      int stmKYNM1 = sysKey.mid(0, 6).toInt();
      int stmKYNM2 = sysKey.mid(7, 6).toInt();
      int stmKYNM3 = sysKey.mid(14, 6).toInt();
      int stmKYNM4 = sysKey.mid(21, 6).toInt();
      int stmKYNM5 = sysKey.mid(28, 6).toInt();

      int crPTKN1 = cryNU1 + 643219 - (4 * stmKYNM1);
      int crPTKN2 = cryNU2 + 952318 - (9 * stmKYNM2);
      int crPTKN3 = cryNU3 + 652945 - (15 * stmKYNM3);
      int crPTKN4 = cryNU4 + 569832 - (3 * stmKYNM4);
      int crPTKN5 = cryNU5 + 754319 - (6 * stmKYNM5);

      QString skENO;
      skENO += QString::number( crPTKN1 ) + "-";
      skENO += QString::number( crPTKN2 ) + "-";
      skENO += QString::number( crPTKN3 ) + "-";
      skENO += QString::number( crPTKN4 ) + "-";
      skENO += QString::number( crPTKN5 ) + "-";

      QList <qulonglong> crPTKNs;
      crPTKNs << crPTKN1 << crPTKN2 << crPTKN3 << crPTKN4 << crPTKN5;
      skENO += QString::number( cks( crPTKNs ) );

      return skENO;
}
// ##



// ##
QString Royalty::deSYKY(QString skENO) {

      QstIGS stIGS("ExampleCompany", "MyApp");

      int cryNU1 = (stIGS.value("dsn1").toString().mid(45, 8)).toInt();
      int cryNU2 = (stIGS.value("dsn7").toString().mid(9, 8)).toInt();
      int cryNU3 = (stIGS.value("dsn4").toString().mid(36, 8)).toInt();
      int cryNU4 = (stIGS.value("dsn5").toString().mid(27, 8)).toInt();
      int cryNU5 = (stIGS.value("dsn2").toString().mid(36, 8)).toInt();

      int skENONum1 = skENO.mid(0, 8).toInt();
      int skENONum2 = skENO.mid(9, 8).toInt();
      int skENONum3 = skENO.mid(18, 8).toInt();
      int skENONum4 = skENO.mid(27, 8).toInt();
      int skENONum5 = skENO.mid(36, 8).toInt();

      int deCRKN1 = (cryNU1 + 7634213 - skENONum1) / 4 ;
      int deCRKN2 = (cryNU2 + 4563218 - skENONum2) / 2 ;
      int deCRKN3 = (cryNU3 + 8754308 - skENONum3) / 8 ;
      int deCRKN4 = (cryNU4 + 5672318 - skENONum4) / 5 ;
      int deCRKN5 = (cryNU5 + 9654275 - skENONum5) / 7 ;

      QString syKYDC;
      syKYDC += QString::number( deCRKN1 ) + "-";
      syKYDC += QString::number( deCRKN2 ) + "-";
      syKYDC += QString::number( deCRKN3 ) + "-";
      syKYDC += QString::number( deCRKN4 ) + "-";
      syKYDC += QString::number( deCRKN5 ) + "-";

      QList <qulonglong> dcrNMS;
      dcrNMS << deCRKN1 << deCRKN2 << deCRKN3 << deCRKN4 << deCRKN5;
      syKYDC += QString::number( cks( dcrNMS ) );

      return syKYDC;
}


QString Royalty::enACKY(QString actKey) {

      QstIGS stIGS("ExampleCompany", "MyApp");

      int cryNU1 = (stIGS.value("dsn5").toString().mid(36, 8)).toInt();
      int cryNU2 = (stIGS.value("dsn3").toString().mid(27, 8)).toInt();
      int cryNU3 = (stIGS.value("dsn9").toString().mid(36, 8)).toInt();
      int cryNU4 = (stIGS.value("dsn2").toString().mid(9, 8)).toInt();
      int cryNU5 = (stIGS.value("dsn1").toString().mid(36, 8)).toInt();

      int acKYENMB1 = actKey.mid(0, 6).toInt();
      int acKYENMB2 = actKey.mid(7, 6).toInt();
      int acKYENMB3 = actKey.mid(14, 6).toInt();
      int acKYENMB4 = actKey.mid(21, 6).toInt();
      int acKYENMB5 = actKey.mid(28, 6).toInt();

      int crAKYN1 = cryNU1 + 65439876 - (4 * acKYENMB1);
      int crAKYN2 = cryNU2 + 45467834 - (7 * acKYENMB2);
      int crAKYN3 = cryNU3 + 23456782 - (3 * acKYENMB3);
      int crAKYN4 = cryNU4 + 45467345 - (9 * acKYENMB4);
      int crAKYN5 = cryNU5 + 31689453 - (6 * acKYENMB5);

      QString acKYECNM;
      acKYECNM += QString::number( crAKYN1 ) + "-";
      acKYECNM += QString::number( crAKYN2 ) + "-";
      acKYECNM += QString::number( crAKYN3 ) + "-";
      acKYECNM += QString::number( crAKYN4 ) + "-";
      acKYECNM += QString::number( crAKYN5 ) + "-";

      QList <qulonglong> crAKYNs;
      crAKYNs << crAKYN1 << crAKYN2 << crAKYN3 << crAKYN4 << crAKYN5;
      acKYECNM += QString::number( cks( crAKYNs ) );

      return acKYECNM;
}


QString Royalty::deACKY(QString acKYECNM) {

      QstIGS stIGS("ExampleCompany", "MyApp");

      int cryNU1 = (stIGS.value("dsn5").toString().mid(18, 8)).toInt();
      int cryNU2 = (stIGS.value("dsn6").toString().mid(9, 8)).toInt();
      int cryNU3 = (stIGS.value("dsn5").toString().mid(27, 8)).toInt();
      int cryNU4 = (stIGS.value("dsn1").toString().mid(36, 8)).toInt();
      int cryNU5 = (stIGS.value("dsn3").toString().mid(36, 8)).toInt();

      int acKYENNu1 = acKYECNM.mid(0, 8).toInt();
      int acKYENNu2 = acKYECNM.mid(9, 8).toInt();
      int acKYENNu3 = acKYECNM.mid(18, 8).toInt();
      int acKYENNu4 = acKYECNM.mid(27, 8).toInt();
      int acKYENNu5 = acKYECNM.mid(36, 8).toInt();

      int decrAKYN1 = (cryNU1 + 68453329 - acKYENNu1) / 2 ;
      int decrAKYN2 = (cryNU2 + 48276371 - acKYENNu2) / 3 ;
      int decrAKYN3 = (cryNU3 + 97534214 - acKYENNu3) / 7 ;
      int decrAKYN4 = (cryNU4 + 56324621 - acKYENNu4) / 5 ;
      int decrAKYN5 = (cryNU5 + 78954212 - acKYENNu5) / 1 ;

      QString acKYDCD;
      acKYDCD += QString::number( decrAKYN1 ) + "-";
      acKYDCD += QString::number( decrAKYN2 ) + "-";
      acKYDCD += QString::number( decrAKYN3 ) + "-";
      acKYDCD += QString::number( decrAKYN4 ) + "-";
      acKYDCD += QString::number( decrAKYN5 ) + "-";

      QList <qulonglong> decrAKYNs;
      decrAKYNs << decrAKYN1 << decrAKYN2 << decrAKYN3 << decrAKYN4 << decrAKYN5;
      acKYDCD += QString::number( cks( decrAKYNs ) );

      return acKYDCD;
}


bool Royalty::starC () {

      QstIGS stIGS("ExampleCompany", "MyApp");
      QString dsn5 = stIGS.value("dsn9").toString();

      if ( dsn5.isEmpty() )  {
                  return true;
            }  else  {
                   return false;
            }
}


void Royalty::iNSTM () {

      QList<qulonglong> nuINMX;
      nuINMX = cNUMAX();

      nuINMX.replace(5, cks( nuINMX.mid(0, 5) ));
      nuINMX.replace(11, cks( nuINMX.mid(6, 5) ));
      nuINMX.replace(17, cks( nuINMX.mid(12, 5) ));
      nuINMX.replace(23, cks( nuINMX.mid(18, 5) ));
      nuINMX.replace(29, cks( nuINMX.mid(24, 5) ));
      nuINMX.replace(35, cks( nuINMX.mid(30, 5) ));
      nuINMX.replace(41, cks( nuINMX.mid(36, 5) ));
      nuINMX.replace(47, cks( nuINMX.mid(42, 5) ));
      nuINMX.replace(53, cks( nuINMX.mid(48, 5) ));
      nuINMX.replace(59, cks( nuINMX.mid(54, 5) ));

      QstIGS stIGS("ExampleCompany", "MyApp");
      QString output;
      int  count = 0;

      for (int x = 0; x < nuINMX.size(); ++x) {
          if (  (x + 1) % 6 == 0  ) {
              output += QString::number ( nuINMX.value(x)  );
              stIGS.setValue(QString("dsn%1").arg(count++), output);
              output = "";
          } else {
              output += QString::number ( nuINMX.value(x)  ) + '-';
          }
      }
}


bool Royalty::cACK () {

      QString etKY = ui->fcLineEdit->text();
      QString ccKY = geAKY( geSKY()  );

      if (etKY == ccKY)
        {
           return true;
        }
      else
        {
           return false;
        }
}


QString Royalty::geSKY ()
{
      QList <qulonglong> hdwKYNU;
      hdwKYNU = cSK(  gSN()  );

      QString rcSG;
      for (int x = 0; x < hdwKYNU.size(); ++x) {
                  rcSG += QString::number ( hdwKYNU.value(x) );
                  if (0 != (x + 1 )% 6)                  rcSG += "-";
      }

      if ( rcSG.isEmpty() || rcSG.length() != 41 )
            rcSG = "error" ;

      return  rcSG;
}



QString Royalty::geAKY (QString stmKE){

      QString acString = "error";

      if ( !stmKE.isEmpty() ) {
            bool ok;
            int part1 = stmKE.mid(0, 6).toInt(&ok, 10);
            int part2 = stmKE.mid(7, 6).toInt(&ok, 10);
            int part3 = stmKE.mid(14, 6).toInt(&ok, 10);
            int part4 = stmKE.mid(21, 6).toInt(&ok, 10);
            int part5 = stmKE.mid(28, 6).toInt(&ok, 10);

            if (ok  == false) {
                  return acString;
            }

            QString part1Str = QString::number ( (part1 + 74653421) * 92).right(6);
            QString part2Str = QString::number ( (part2 + 23241234) * 17 ).right(6);
            QString part3Str = QString::number ( (part3 + 45876233) * 73 ).right(6);
            QString part4Str = QString::number ( (part4 + 12876352) * 43 ).right(6);
            QString part5Str = QString::number ( (part5 + 65312298) * 65 ).right(6);

            QString acString;
            QList <qulonglong> partsList;

            partsList << part1Str.toInt(&ok, 10) << part2Str.toInt(&ok, 10) << part3Str.toInt(&ok, 10) << part4Str.toInt(&ok, 10) << part5Str.toInt(&ok, 10) ;
            acString = part1Str + "-" + part2Str + "-" + part3Str + "-" + part4Str+ "-" + part5Str + "-" + QString::number(  cks(partsList)  ) ;

            return acString;

      }

      return acString;
}



QList <qulonglong> Royalty::cNUMAX ()
{
    QList<qulonglong> integerList;
    qulonglong lrgRDVAL;

    for (int i = 0; i < 60; ++i) {

       lrgRDVAL =  qrand() * 9999;
       integerList << (lrgRDVAL % ((99999999 + 1) - 10000000) + 10000000);
    }

    return integerList;
}




QList <qulonglong> Royalty::gSN()
{
      QStringList rwHDT;
      foreach (  const QNetworkInterface &ni,  QNetworkInterface::allInterfaces()  )  {
          if ( ! ni.hardwareAddress().isEmpty()  )   {

               #ifdef Q_OS_MAC
                    rwHDT <<  ni.hardwareAddress();
               #endif

              #ifdef Q_OS_WIN32
                    rwHDT <<  ni.name();
              #endif
           }
       }

      rwHDT.replaceInStrings(":", "");
      rwHDT.replaceInStrings("-", "");
      rwHDT.replaceInStrings("{", "");
      rwHDT.replaceInStrings("}", "");

      rwHDT.removeDuplicates();
      qSort(rwHDT.begin(), rwHDT.end());

      QList <qulonglong> returnList;

      bool ok;
      for (int x = 0; x < rwHDT.size(); ++x)
      {

          if (rwHDT.at(x).length() > 16 ) {
                    returnList << (  rwHDT.at(x).left(16).toULongLong(&ok, 16) + rwHDT.at(x).mid(16, 16).toULongLong(&ok, 16)  );
                } else {
                    returnList << rwHDT.at(x).toULongLong(&ok, 16);
          }
      }

      return returnList;
}


QList <qulonglong> Royalty::cSK(QList <qulonglong> hWNUS)
{

      switch ( hWNUS.size()  )
            {
            case 1:
                  hWNUS << hWNUS.at(0) << hWNUS.at(0) << hWNUS.at(0) << hWNUS.at(0);
                  break;
            case 2:
                  hWNUS << hWNUS.at(0) << hWNUS.at(1) << hWNUS.at(0);
                  break;
            case 3:
                  hWNUS << hWNUS.at(0) << hWNUS.at(1);
                  break;
            case 4:
                  hWNUS << hWNUS.at(0);
                  break;
            }


      while (hWNUS.length() >5)
           hWNUS.removeLast();


      int lwLMT = 3765432;
      int urLMT = 8765439;

      hWNUS.replace(0, (((hWNUS.at(0) + 74532176) % (urLMT - lwLMT)) + lwLMT ));
      hWNUS.replace(1, (((hWNUS.at(0) + 97975432) % (urLMT - lwLMT)) + lwLMT ));
      hWNUS.replace(2, (((hWNUS.at(0) + 85643421) % (urLMT - lwLMT)) + lwLMT ));
      hWNUS.replace(3, (((hWNUS.at(0) + 77456423 ) % (urLMT - lwLMT)) + lwLMT ));
      hWNUS.replace(4, (((hWNUS.at(0) + 84563217) % (urLMT - lwLMT)) + lwLMT ));

      hWNUS.insert(5, cks(hWNUS) );

      return hWNUS;
}



void Royalty::tCbo()
{
      Qcbo *cbo = QApplication::cbo();
      QString toCBText = ui->rcLineEdit->text();
      cbo->setText( toCBText );
}



void Royalty::fCbo()
{ 
    Qcbo *cbo = QApplication::cbo();
    QString fromCBText = cbo->text();
    ui->fcLineEdit->setText(  fromCBText );
}



Royalty::~Royalty()
{
    delete ui;
}



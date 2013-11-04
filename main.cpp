#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]){

    Q_INIT_RESOURCE(content);
    QApplication app(argc, argv);

    app.setApplicationName("MyApp");
    app.setOrganizationName("ExampleCompany");

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}


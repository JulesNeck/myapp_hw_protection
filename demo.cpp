#include "demo.h"


Demo::Demo(QWidget *parent) : QWidget(parent), ui(new Ui::Demo)
{
    ui->setupUi(this);
    ui->webViewDemo->setUrl(QUrl("qrc:/content/demo.html"));
}

Demo::~Demo()
{
    delete ui;
}

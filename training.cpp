#include "training.h"


Training::Training(QWidget *parent) : QWidget(parent), ui(new Ui::Training)
{
    ui->setupUi(this);
    ui->webViewTraining->setUrl(QUrl("qrc:/content/start.html"));
}

Training::~Training()
{
    delete ui;
}

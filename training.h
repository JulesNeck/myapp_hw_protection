#ifndef TRAINING_H
#define TRAINING_H

#include "ui_Training.h"


namespace Ui {
    class Training;
}

class Training : public QWidget
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = 0);
    ~Training();

private:
    Ui::Training *ui;
};

#endif // TRAINING_H

#ifndef DEMO_H
#define DEMO_H

#include "ui_Demo.h"


namespace Ui {
    class Demo;
}

class Demo : public QWidget
{
    Q_OBJECT

public:
    explicit Demo(QWidget *parent = 0);
    ~Demo();

private:
    Ui::Demo *ui;
};

#endif // DEMO_H

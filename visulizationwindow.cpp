#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"

VisulizationWindow::VisulizationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisulizationWindow)
{
    ui->setupUi(this);
}

VisulizationWindow::~VisulizationWindow()
{
    delete ui;
}

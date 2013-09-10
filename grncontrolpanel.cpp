#include "grncontrolpanel.h"
#include "ui_grncontrolpanel.h"
#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"

GRNControlPanel::GRNControlPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GRNControlPanel)
{
    ui->setupUi(this);
    connect(ui->OpenVisulizationButton, SIGNAL(clicked()), this, SLOT(openVisulizationWindow()));
}

GRNControlPanel::~GRNControlPanel()
{
    delete ui;
}



void GRNControlPanel::on_OpenVisulizationWindow_clicked()
{
    openVisulizationWindow();
}

void GRNControlPanel::openVisulizationWindow()
{
    GRNVisulizationWindow = new VisulizationWindow();
    GRNVisulizationWindow->show();
}


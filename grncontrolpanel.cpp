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
    connect(ui->pushButtonExit,SIGNAL(clicked()),this, SLOT(close()));
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


void GRNControlPanel::on_inputFileChooseButton_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this, "Open File",QDir::currentPath());
    on_InputFileNameField_textChanged(inputFileName);
}


void GRNControlPanel::on_InputFileNameField_textChanged(const QString &string)
{
    ui->InputFileNameField->setText(string);
}

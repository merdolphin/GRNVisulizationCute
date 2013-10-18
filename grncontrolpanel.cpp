#include "grncontrolpanel.h"
#include "ui_grncontrolpanel.h"
#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"
#include "dataprocessing.h"

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


void GRNControlPanel::openVisulizationWindow()
{
    GRNVisulizationWindow = new VisulizationWindow();
    GRNVisulizationWindow->show();
}


void GRNControlPanel::on_inputFileChooseButton_clicked()
{
    QString inputFilePath = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    on_InputFileNameField_textChanged(inputFilePath);
    dataProcessing::processing(inputFilePath);
}


void GRNControlPanel::on_InputFileNameField_textChanged(const QString &string)
{
    ui->InputFileNameField->setText(string);
}




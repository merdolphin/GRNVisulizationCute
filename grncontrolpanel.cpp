#include "grncontrolpanel.h"
#include "ui_grncontrolpanel.h"
#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"
#include "dataprocessing.h"


 QString layoutAttribute = "dot";
 QString inputFilePath = NULL;

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
    if(inputFilePath.isNull()){
        QMessageBox::information(this,"Image Viewer","Please upload file.");
    }else{
       dataProcessing::processing(inputFilePath, layoutAttribute);
        GRNVisulizationWindow = new VisulizationWindow();
        GRNVisulizationWindow->show();
    }
}


void GRNControlPanel::on_inputFileChooseButton_clicked()
{
    inputFilePath = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    on_InputFileNameField_textChanged(inputFilePath);
}


void GRNControlPanel::on_InputFileNameField_textChanged(const QString &string)
{
    ui->InputFileNameField->setText(string);
}




void GRNControlPanel::on_dot_clicked()
{
    layoutAttribute = "dot";
}

void GRNControlPanel::on_neato_clicked()
{
    layoutAttribute = "neato";
}


void GRNControlPanel::on_fdp_clicked()
{
    layoutAttribute = "fdp";
}

void GRNControlPanel::on_sfdp_clicked()
{
    layoutAttribute = "sfdp";
}

void GRNControlPanel::on_twopi_clicked()
{
    layoutAttribute = "twopi";
}


void GRNControlPanel::on_circo_clicked()
{
    layoutAttribute = "circo";
}

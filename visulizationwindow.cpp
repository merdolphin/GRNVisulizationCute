#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"
#include <QGraphicsScene>
#include "dataprocessing.h"

VisulizationWindow::VisulizationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisulizationWindow)
{
    ui->setupUi(this);

    loadImageToGraphicsView();
    dotFileContentTextEdit_show();
    nodeShapesComboBox();
}

VisulizationWindow::~VisulizationWindow()
{
    delete ui;
}

void VisulizationWindow::loadImageToGraphicsView(){
    QString filePath = QDir::currentPath()+"/tmp";
    QString fileName = filePath + "/graph1.jpg";

    if(! fileName.isEmpty() ){

        QImage image(fileName);

        if(image.isNull()){
            QMessageBox::information(this,"Image Viewer","Error loading image");
            return;
        }

        QGraphicsScene *scene = new QGraphicsScene();

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));

        scene->addItem(item);
        ui->NetworkGraphicsView->setScene(scene);
    }

}


void VisulizationWindow::dotFileContentTextEdit_show()
{
    QString dotFile = QDir::currentPath() +"/tmp/" + "result.dot";

    if (! dotFile.isEmpty() ) {
        QFile file(dotFile);

        if (!file.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open result.dot file"));
            return;
        }
        QTextStream in(&file);
        ui->dotFileContentTextEdit->setText(in.readAll());
        file.close();
    }
}


void VisulizationWindow::on_DefaultTestPushButton_clicked()
{
    dotFileContentTextEdit_show();
}

void VisulizationWindow::on_SaveTextPushButton_clicked()
{
    saveTextEditToDotFile("result.dot");
}

void VisulizationWindow::saveTextEditToDotFile(QString filename){
    QString newdotFileName = QDir::currentPath()+"/tmp/"+filename;
    QFile file(newdotFileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << ui->dotFileContentTextEdit->toPlainText() << endl;
        file.close();
    }
}


void VisulizationWindow::on_RefreshTextPushButton_clicked()
{
    saveTextEditToDotFile("tmpresult.dot");
    QProcess::execute("dot -Tps tmp/tmpresult.dot -o tmp/graph1.jpg");
    RefreshFigure();
}


void VisulizationWindow::RefreshFigure(){
    QProcess::execute("mogrify tmp/graph1.jpg tmp/graph1.jpg ");
    loadImageToGraphicsView();
}

void VisulizationWindow::nodeShapesComboBox(){
    QString nodeShapes [56] = {"ellipse","box", "polygon","oval","circle","point","egg","triangle","plaintext","diamond","trapezium","parallelogram","house","pentagon","hexagon","septagon","octagon","doublecircle","doubleoctagon","tripleoctagon","invtriangle","invtrapezium","invhouse","Mdiamond","Msquare","Mcircle","rect","rectangle","square","star","none","note","tab","folder","box3d","component","promoter","cds","terminator","utr","primersite","restrictionsite","fivepoverhang","threepoverhang","noverhang","assembly","signature","insulator","ribosite","rnastab","proteasesite","proteinstab","rpromoter","rarrow","larrow","lpromoter"};
    int i;
    for(i=0; i<56; i++){
        ui->comboBoxNodeShapes->addItem((nodeShapes[i]));
    }
}


void VisulizationWindow::on_comboBoxNodeShapes_activated(const QString &arg1)
{
    dataProcessing::writeToDotFile(arg1);
    dotFileContentTextEdit_show();
    QProcess::execute("dot -Tps tmp/result.dot -o tmp/graph1.jpg");
    RefreshFigure();
}


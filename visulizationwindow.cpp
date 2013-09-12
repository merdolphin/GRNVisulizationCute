#include "visulizationwindow.h"
#include "ui_visulizationwindow.h"
#include <QGraphicsScene>

VisulizationWindow::VisulizationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisulizationWindow)
{
    ui->setupUi(this);

    loadImageToGraphicsView();
    dotFileContentTextEdit_show();


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

        if (!file.open(QIODevice::ReadOnly)) {
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

    QString newdotFileName = QDir::currentPath()+"/tmp/"+"result.dot";
    QFile file(newdotFileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << ui->dotFileContentTextEdit->toPlainText() << endl;
        file.close();
    }
}

void VisulizationWindow::on_RefreshTextPushButton_clicked()
{
    QProcess::execute("dot -Tps tmp/result.dot -o tmp/graph1.jpg");
    QProcess::execute("mogrify tmp/graph1.jpg tmp/graph1.jpg ");
    loadImageToGraphicsView();
}


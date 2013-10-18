#ifndef VISULIZATIONWINDOW_H
#define VISULIZATIONWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>


namespace Ui {
class VisulizationWindow;
}

class VisulizationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VisulizationWindow(QWidget *parent = 0);
    ~VisulizationWindow();

private slots:
    void loadImageToGraphicsView();
    void dotFileContentTextEdit_show();
    void on_DefaultTestPushButton_clicked();
    void on_SaveTextPushButton_clicked();
    void on_RefreshTextPushButton_clicked();
    void saveTextEditToDotFile(QString);
    void addnodeShapesComboBox();
    void on_comboBoxNodeShapes_activated(const QString &arg1);
    void RefreshFigure();
    void on_comboBoxLayout_activated(const QString &arg1);
    void addcomboBoxNodeColor();
    void on_comboBoxNodeColor_activated(const QString &arg1);
    void addcomboBoxNodeStyle();
    void on_comboBoxNodeStyle_activated(const QString &arg1);
    void fileMenuLoadAction();
    void exportDotFile();
    void exportFigureFile();

private:
    QGraphicsScene *scene;
    Ui::VisulizationWindow *ui;
};

#endif // VISULIZATIONWINDOW_H

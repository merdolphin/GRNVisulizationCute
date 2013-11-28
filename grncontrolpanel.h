#ifndef GRNCONTROLPANEL_H
#define GRNCONTROLPANEL_H

#include <QMainWindow>
#include "visulizationwindow.h"

namespace Ui {
class GRNControlPanel;
}

class GRNControlPanel : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GRNControlPanel(QWidget *parent = 0);
    ~GRNControlPanel();
    static QString getFilePath();

private:
    VisulizationWindow *GRNVisulizationWindow;

private slots:

    void openVisulizationWindow();
    void on_inputFileChooseButton_clicked();
    void on_InputFileNameField_textChanged(const QString &arg1);

    void on_dot_clicked();

    void on_neato_clicked();

    void on_fdp_clicked();

    void on_sfdp_clicked();

    void on_twopi_clicked();

    void on_circo_clicked();

private:
    Ui::GRNControlPanel *ui;
};

#endif // GRNCONTROALPANEL_H

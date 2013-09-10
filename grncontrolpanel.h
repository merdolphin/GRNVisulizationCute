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


public slots:
    void openVisulizationWindow();

private:
    VisulizationWindow *GRNVisulizationWindow;

private slots:
    void on_OpenVisulizationWindow_clicked();

private:
    Ui::GRNControlPanel *ui;
};

#endif // GRNCONTROALPANEL_H

#ifndef VISULIZATIONWINDOW_H
#define VISULIZATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class VisulizationWindow;
}

class VisulizationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VisulizationWindow(QWidget *parent = 0);
    ~VisulizationWindow();
    
private:
    Ui::VisulizationWindow *ui;
};

#endif // VISULIZATIONWINDOW_H

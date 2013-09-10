#include <QApplication>
#include "grncontrolpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GRNControlPanel w;
    w.show();
    
    return a.exec();
}

/*** Written by lina <lina.oahz@gmail.com>
 *   on  Wed Sep 11 23:06:45 SGT 2013
 ***/

#include <QApplication>
#include "grncontrolpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GRNControlPanel w;
    w.show();
    
    return a.exec();
}

/*** Written by lina <lina.oahz@gmail.com>
 *   on  Wed Sep 11 23:06:45 SGT 2013
 ***/

#include <QApplication>
#include "grncontrolpanel.h"
#include "dataprocessing.h"


int main(int argc, char *argv[])
{
    dataProcessing();

    QApplication a(argc, argv);
    GRNControlPanel w;
    w.show();
    //w.hide();

    return a.exec();

}

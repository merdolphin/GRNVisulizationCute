#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include <Qt>
#include "pair.h"


class dataProcessing
{
public:

    dataProcessing();

    static void processing(QString);

    static void writeToDotFile(QString, QString, QString);
    static void readFinalnetworkIntoList(QString);
    static void dotFileToGraph();

};


#endif // DATAPROCESSING_H

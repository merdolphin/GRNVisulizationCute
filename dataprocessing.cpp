#include "dataprocessing.h"

#include <Qt>
#include <QtCore>
#include <qalgorithms.h>
#include "pair.h"
#include "grncontrolpanel.h"


QList<pair> nodespair;
QList<QString> allnodes;


QString outputDotFileName = "tmp/result.dot";


dataProcessing::dataProcessing(){

}

void dataProcessing::processing(QString finalNetworkfilepath)
{


    QString finalOutputFilePath = finalNetworkfilepath;

    QString defaultnodestyle = "solid";
    QString defaultnodeshape = "ellipse";
    QString defaultcolor = "black";

    readFinalnetworkIntoList(finalOutputFilePath);
    writeToDotFile(defaultnodestyle, defaultnodeshape, defaultcolor);
    dotFileToGraph();
}

void dataProcessing::readFinalnetworkIntoList(QString finalOutputFile)
{

    QFile file(finalOutputFile);

    if(file.open((QIODevice::ReadOnly))){
        QTextStream in(&file);
        while( !in.atEnd() ){
            QString string = in.readLine();
            QStringList tmpList = string.split("\t",QString::KeepEmptyParts);
            if( tmpList[2] != "0" ){
                int i;
                for(i=0; i<nodespair.size(); i++){
                    if(tmpList[0] == nodespair[i].source && tmpList[1] == nodespair[i].target)
                        break;
                }
                if(i == nodespair.size()){

                    pair np;
                    np.setnodepair(tmpList[0],tmpList[1]);
                    nodespair.append(np);

                    if( ! allnodes.contains(tmpList[0]) )
                        allnodes.append(tmpList[0]);
                    if( ! allnodes.contains(tmpList[1]))
                        allnodes.append(tmpList[1]);

                }
            }
        }
    }
}


void dataProcessing::writeToDotFile(QString nodestyle, QString nodeshape, QString nodecolor){
    QFile ofile(outputDotFileName);
    if(ofile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&ofile);
        stream << "digraph graphname{ \n \t node [style=" << nodestyle << ", shape=" << nodeshape << ", color=" << nodecolor << " ]" << endl;

        stream << endl;

        for(int i = 0; i<nodespair.size(); i++){
            stream << "\t" << nodespair[i].source << "->" << nodespair[i].target << endl;
        }

        stream << endl;

        qSort(allnodes.begin(),allnodes.end());
        for(int i=0; i<allnodes.size(); i++){
            stream << "\t" << allnodes[i] << endl;
        }
        stream << "}" << endl;
    }
    ofile.close();
}

void dataProcessing::dotFileToGraph(){
        QString layoutcmd = "dot -Tps tmp/result.dot -o tmp/graph1.jpg";
        QProcess::execute(layoutcmd);
        QProcess::execute("mogrify tmp/graph1.jpg tmp/graph1.jpg ");
}



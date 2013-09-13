#ifndef PAIR_H
#define PAIR_H

#include <QString>

class pair
{
public:
    pair();

    QString source;
    QString target;

    void setnodepair(QString source, QString target);
};

#endif // PAIR_H

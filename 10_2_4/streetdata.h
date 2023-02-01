#ifndef STREETDATA_H
#define STREETDATA_H

#include <QVector>

class StreetData : public QVector<QVector<int>>
{
public:
    StreetData();

    void donateToStreet(int street_idx, int amount);
    bool hasGoodStandard(int street_idx);
};

#endif // STREETDATA_H

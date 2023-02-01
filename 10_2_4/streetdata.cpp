#include "streetdata.h"

#include <QRandomGenerator>

StreetData::StreetData()
{
    resize(5, QVector<int>(5));
    for(auto & row : *this) {
        for(auto & element : row) {
            element =
                    QRandomGenerator::global()->bounded(-50, 51);
        }
    }
}

void StreetData::donateToStreet(int street_idx, int amount)
{
    for (auto & family_standard : (*this)[street_idx]) {
        family_standard += amount;
    }
}

bool StreetData::hasGoodStandard(int street_idx)
{
    for(const auto & famili_standard : this->at(street_idx)) {
       if(famili_standard < 0) { return false; }
    }

    return true;
}

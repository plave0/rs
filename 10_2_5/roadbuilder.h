#ifndef ROADBUILDER_H
#define ROADBUILDER_H

#include "road.h"
#include "city.h"

#include <QList>
#include <QString>
#include <QMutex>

class RoadBuilder : QList<Road>
{
public:
    RoadBuilder();

    void addRoad(City& c1, City& c2) { this->emplaceBack(c1, c2); }
    const Road& getLastRoad() { return this->at(length() - 1); }

};

#endif // ROADBUILDER_H

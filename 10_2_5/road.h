#ifndef ROAD_H
#define ROAD_H

#include "city.h"

#include <QString>

class Road : public QPair<City, City>
{
public:
    Road(City c1, City c2);

    QString toQString() const;
    const inline City& start() const { return first; }
    const inline City& destination() const { return second; }

    friend bool operator==(const Road& lhs, const Road& rhs)
        { return lhs.first == rhs.first && lhs.second == lhs.second; }
};

#endif // ROAD_H

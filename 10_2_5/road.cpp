#include "road.h"

Road::Road(City c1, City c2)
    :QPair<City, City>(c1, c2)
{}

QString Road::toQString() const
{
    return first.name() + QString(" to ") + second.name();
}

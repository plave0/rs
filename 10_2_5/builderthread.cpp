#include "builderthread.h"

#include "city.h"
#include "roadbuilder.h"
#include <QThread>

BuilderThread::BuilderThread(QList<City> &cities,
                             RoadBuilder &builder,
                             const int city_idx
                             ):
    QThread(),
    m_cities(cities),
    m_road_builder(builder),
    m_city_idx(city_idx)
{}

void BuilderThread::run()
{

    msleep(1000);

    int next_idx {};
    double min_distance {qInf()};

    for(auto i = 0u; i != m_cities.length(); ++i) {
        if(i == m_city_idx || m_cities[i].isVisited()) { continue; }

            double next_distance = cityDistance(
                        m_cities[m_city_idx],
                        m_cities[i]
                        );

            if (next_distance < min_distance) {
                min_distance = next_distance;
                next_idx = i;
            }
    }

    m_road_builder.addRoad(m_cities[m_city_idx], m_cities[next_idx]);
}

double BuilderThread::cityDistance(const City &city1, const City &city2)
{
    return sqrt(
                (city1.x() - city2.x()) * (city1.x() - city2.x()) +
                (city1.y() - city2.y()) * (city1.y() - city2.y())
                );
}




#ifndef BUILDERTHREAD_H
#define BUILDERTHREAD_H

#include "city.h"
#include "roadbuilder.h"

#include <QThread>
#include <QList>

class BuilderThread : public QThread
{
    Q_OBJECT
public:
    BuilderThread(QList<City> &cities,
                  RoadBuilder &builder,
                  const int city_idx
                  );

protected:
    void run() override;

private:
    double cityDistance(const City &city1, const City &city2);

    QList<City>& m_cities;
    RoadBuilder& m_road_builder;
    const int m_city_idx;
};

#endif // BUILDERTHREAD_H

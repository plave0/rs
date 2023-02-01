#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QVariant>

class City
{
public:
    City() {}
    City(const QVariant &variant) { fromQVariant(variant); }

    inline void visited() { m_visited = true; }
    inline bool isVisited() const { return m_visited; }
    inline const QString& name() const { return m_name; }
    inline double x() const { return m_x; }
    inline double y() const { return m_y; }

    QString toQString() const;
    void fromQVariant(const QVariant &variant);

private:
    QString m_name {};
    double m_x {};
    double m_y {};
    bool m_visited {};

    friend bool operator== (const City& c1, const City& c2)
    { return c1.m_name == c2.m_name && fabs(c1.m_x - c2.m_x) < 1e-6 && fabs(c1.m_y - c2.m_y) < 1e-6; }


};

#endif // CITY_H

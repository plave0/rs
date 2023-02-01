#include "city.h"

#include <QString>
#include <QVariant>

QString City::toQString() const
{
    return QString(m_name+
                   " ---> ("+
                   QString::number(m_x)+
                   ", "+
                   QString::number(m_y)+
                   ")"
                   );
}

void City::fromQVariant(const QVariant &variant)
{
    QVariantMap map = variant.toMap();
    m_name = map["name"].toString();
    m_x = map["x"].toDouble();
    m_y = map["y"].toDouble();
    m_visited = false;
}

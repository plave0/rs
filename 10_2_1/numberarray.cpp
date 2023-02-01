#include "numberarray.h"

#include <QRandomGenerator>

NumberArray::NumberArray(size_t size) :
    QVector<qint32>(size)
{
    QVector<qint32>::resize(size);
    for(auto & element : *this) {
        element = QRandomGenerator::global()->bounded(-100, 101);
    }
}

QString NumberArray::toQString()
{
    QString res {};
    for (const auto & element : *this) {
        res.append(QString::number(element));
        res.append(" ");
    }
    res.remove(res.length() - 1, 1);

    return res;
}

qint32 NumberArray::sumAt(size_t start, size_t end)
{

    auto start_iter = this->begin() + start;
    auto end_iter = this->begin() + end + 1;

    qint32 sum {0};
    for(auto it = start_iter; it != end_iter && (it + 1) != this->end(); ++it) {
        sum += (*(it + 1) - *it);
    }

    return sum;
}

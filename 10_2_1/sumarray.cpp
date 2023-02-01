#include "sumarray.h"

#include <QVector>


void SumArray::appendSum(qint32 sum)
{
    QMutexLocker this_lock(&m_this_mutex);
    this->append(sum);
}

qint32 SumArray::calcResult()
{
    QMutexLocker this_lock(&m_this_mutex);

    for (const auto & element : *this) {
        m_total_sum += element;
    }

    return m_total_sum;
}

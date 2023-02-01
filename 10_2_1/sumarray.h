#ifndef SUMARRAY_H
#define SUMARRAY_H

#include <QVector>
#include <QMutex>
#include <QSharedPointer>

class SumArray : private QVector<qint32>
{
public:
    SumArray() : QVector<qint32>() {}

    void appendSum(qint32 sum);
    qint32 calcResult();

private:

    QMutex m_this_mutex;
    qint32 m_total_sum;

};

#endif // SUMARRAY_H

#include "sumthread.h"
#include "sumarray.h"
#include "numberarray.h"

#include <QThread>
#include <QDebug>

SumThread::SumThread(NumberArray &num_array,
                     SumArray& sum_array,
                     size_t start, size_t end)
    :QThread(),
      m_num_array(num_array),
      m_sum_array(sum_array),
      m_start(start),
      m_end(end)
{}

void SumThread::run()
{
    qInfo() << m_start << " " << m_end;
    qint32 sum = m_num_array.sumAt(m_start, m_end);
    qInfo() << sum;
    m_sum_array.appendSum(m_num_array.sumAt(m_start, m_end));
}

#ifndef SUMTHREAD_H
#define SUMTHREAD_H

#include <numberarray.h>
#include <sumarray.h>

#include <QThread>

class SumThread : public QThread
{
    Q_OBJECT
public:
    SumThread(NumberArray& num_array,
              SumArray& sum_array,
              size_t start, size_t end);

protected:
    void run() override;

private:
    NumberArray& m_num_array;
    SumArray& m_sum_array;
    const size_t m_start;
    const size_t m_end;
};

#endif // SUMTHREAD_H

#ifndef TRANSACTIONTHREAD_H
#define TRANSACTIONTHREAD_H

#include "bank.h"

#include <QThread>

class TransactionThread : public QThread
{
    Q_OBJECT
public:
    TransactionThread(Bank& bank, quint16 destination_node, qint32 amount);
protected:
    void run() override;

private:
    Bank& m_bank;
    quint16 m_destination_node;
    qint32 m_amount;
};

#endif // TRANSACTIONTHREAD_H

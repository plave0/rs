#include "transactionthread.h"
#include "bank.h"

#include <QDebug>

TransactionThread::TransactionThread(
        Bank& bank,
        quint16 destination_node,
        qint32 amount
        ):
    QThread(),
    m_bank(bank),
    m_destination_node(destination_node),
    m_amount(amount)
{}

void TransactionThread::run()
{
    m_bank.makeTransaction(m_destination_node, m_amount);
}

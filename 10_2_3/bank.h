#ifndef BANK_H
#define BANK_H

#include <QList>
#include <QMutex>
#include <QSharedPointer>

class Bank
{
public:
    Bank();

    inline const QList<qint32>& resources() const { return m_resources; }

    void generateResources(quint32 resources_to_alocate);
    void makeTransaction(size_t destination_node, qint32 amount);
private:
    QList<qint32> m_resources;
    QMutex m_resources_lock;
};

#endif // BANK_H

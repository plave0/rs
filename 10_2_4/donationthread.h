#ifndef DONATIONTHREAD_H
#define DONATIONTHREAD_H

#include "streetdata.h"

#include <QThread>

class DonationThread : public QThread
{
    Q_OBJECT
public:
    DonationThread(StreetData& street_data, int street_idx);

protected:
    void run() override;

private:
    StreetData& m_street_data;
    int m_street_idx;

signals:
    void donationFinished(int street_idx, int donation_amount);
};

#endif // DONATIONTHREAD_H

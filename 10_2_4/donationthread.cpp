#include "donationthread.h"
#include "streetdata.h"

#include <QRandomGenerator>

DonationThread::DonationThread(StreetData& street_data, int street_idx)
    : QThread()
    , m_street_data(street_data)
    , m_street_idx(street_idx)
{}

void DonationThread::run()
{
    int random_wait =
            QRandomGenerator::global()->bounded(1, 6);

    sleep(random_wait);

    int randomo_donation_amount =
            QRandomGenerator::global()->bounded(5, 16);

    m_street_data.donateToStreet(m_street_idx, randomo_donation_amount);

    emit donationFinished(m_street_idx, randomo_donation_amount);
}

#include "source.h"

#include <QString>
#include <QVariant>

Source::Source()
{}

Source::Source(const QString &naziv, quint32 pocetna_zapremina) :
    m_naziv(naziv),
    m_zapremina(std::move(pocetna_zapremina))
{}

Source::Source(const QVariant & variant) {
    fromQVarian(variant);
}

quint32 Source::drainSource(quint32 amount) {
    quint32 amount_to_drain = qMin(amount, m_zapremina);
    m_zapremina -= amount_to_drain;
    return amount_to_drain;
}

void Source::fromQVarian(QVariant variant) {
    QVariantMap mapa = variant.toMap();
    m_naziv = mapa.value("name").toString();
    m_zapremina = mapa.value("volume").toUInt();
}

QString Source::toQString() const {
    return m_naziv +
            QString{" - "} +
            (m_zapremina == 0 ?
                 QString{"izvor je iscrpljen"} :
QString::number(m_zapremina));
}


#ifndef SOURCE_H
#define SOURCE_H

#include <QVariant>

class Source
{

public:
    Source();
    Source(const QString &naziv, quint32 pocetna_zapremina);
    Source(const QVariant & variant);

    inline quint32 volume() const { return m_zapremina; }
    inline quint32 isDrained() const { return m_zapremina == 0u; }

    void fromQVarian(QVariant variant);
    QString toQString() const;
    quint32 drainSource(quint32 amount);
private:
    QString m_naziv;
    quint32 m_zapremina;

};

#endif // SOURCE_H

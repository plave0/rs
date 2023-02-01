#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <QVector>
#include <QString>

class NumberArray : public QVector<qint32>
{
public:
    NumberArray(size_t size);

    QString toQString();
    qint32 sumAt(size_t start,
                 size_t end);
};

#endif // NUMBERARRAY_H

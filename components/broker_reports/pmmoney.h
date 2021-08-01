#ifndef PMMONEY_H
#define PMMONEY_H

#include <QObject>
#include <QDataStream>
#include <QMetaEnum>
#include <exception>
#include <stdexcept>

class PMCurrency : public QObject{
    Q_OBJECT
public:
    // ISO 4217
    typedef enum {
        USD = 840,
        EUR = 978,
        RUB = 643
    } pm_currency_t;
    Q_ENUM(pm_currency_t)
};


template <PMCurrency::pm_currency_t C>
class PMMoney
{
public:

    PMMoney();
    PMMoney(qint64 value_centum);

    // Full value in cents
    qint64 get_value_centum(void) const;

    // Moneta part of value
    qint64 get_moneta(void) const;

    // Centum part of value
    qint64 get_centum(void) const;

    void set_full_value(qint64 centum);
    void set_full_value(qint64 moneta, qint64 centum);

    PMCurrency::pm_currency_t get_currency(void) const;
    QString get_str_currency(void) const;

    friend QDataStream& operator <<(QDataStream& stream, const PMMoney& money);

    friend PMMoney operator+(const PMMoney &money_l, const PMMoney &money_r);
private:
    qint64 value; // centum
};

#endif // PMMONEY_H
#ifndef PMMONEY_H
#define PMMONEY_H

#include <QtGlobal>
#include <QObject>
#include <QDataStream>
#include <QMetaEnum>
#include <QDebug>

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

class PMMoney : public PMCurrency
{
protected:
    qint64 value;
    PMCurrency::pm_currency_t m_currency;
public:

    PMMoney();
    PMMoney(const PMMoney& money);
    PMMoney(qint64 value_centum, PMCurrency::pm_currency_t currency);

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

    friend QDataStream& operator <<(QDataStream& stream, const PMMoney& money){
        QString out;
        out = QString::number(money.get_moneta()) + '.' + QString::number(money.get_centum());
        return stream << out;
    }

    friend QDebug operator<<(QDebug dbg, const PMMoney &money){
        QString out;
        out = QString::number(money.get_moneta()) + '.' + QString::number(money.get_centum());
        return dbg << out;
    }

    friend PMMoney operator+(const PMMoney &money_l, const PMMoney &money_r){
        if(money_l.m_currency != money_r.m_currency){
            qCritical() << "Different currency!";
            Q_ASSERT(true);
        }
        return PMMoney(money_l.value + money_r.value, money_l.m_currency);
    }

    friend PMMoney operator-(const PMMoney &money_l, const PMMoney &money_r){
        if(money_l.m_currency != money_r.m_currency){
            qCritical() << "Different currency!";
            Q_ASSERT(true);
        }
        return PMMoney(money_l.value - money_r.value, money_l.m_currency);
    }

    PMMoney& operator= (const PMMoney &money){
        value = money.value;
        m_currency = money.m_currency;
        return *this;
    }
};

#endif // PMMONEY_H

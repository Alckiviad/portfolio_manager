#include "pmmoney.h"

PMMoney::PMMoney()
    : value{0},
      currency{PMMoney::USD}
{
}

PMMoney::PMMoney(qint64 value_centum, pm_currency_t cur)
    : value{value_centum},
      currency{cur}
{
}

qint64 PMMoney::get_value_centum(void) const
{
    return value;
}

qint64 PMMoney::get_moneta(void) const{
    return (value / 100);
}

qint64 PMMoney::get_centum(void) const{
    return (value % 100);
}

void PMMoney::set_full_value(qint64 centum){
    value = centum;
}

void PMMoney::set_full_value(qint64 moneta, qint64 centum){
    value = moneta * 100 + centum;
}

PMMoney::pm_currency_t PMMoney::get_currency(void) const{
    return currency;
}

QString PMMoney::get_str_currency(void) const{
    QMetaEnum metaEnum = QMetaEnum::fromType<PMMoney::pm_currency_t>();
    return metaEnum.valueToKey(PMMoney::currency);
}

void PMMoney::set_currency(pm_currency_t cur){
    currency = cur;
}

QDataStream& operator <<(QDataStream& stream, const PMMoney& money){
    return stream << money.get_moneta() << '.' << money.get_centum() << ' '
                  << money.get_str_currency();
}

PMMoney operator+(const PMMoney &money_l, const PMMoney &money_r){
    if(money_l.currency != money_r.currency){
        throw std::invalid_argument("Addition of different carrency!");
    }
    return PMMoney(money_l.value + money_r.value, money_l.currency);
}

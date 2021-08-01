#include "pmmoney.h"

template <PMCurrency::pm_currency_t C>
PMMoney<C>::PMMoney()
    : value{0}
{
}

template <PMCurrency::pm_currency_t C>
PMMoney<C>::PMMoney(qint64 value_centum)
    : value{value_centum}
{
}


template <PMCurrency::pm_currency_t C>
qint64 PMMoney<C>::get_value_centum(void) const
{
    return value;
}

template <PMCurrency::pm_currency_t C>
qint64 PMMoney<C>::get_moneta(void) const{
    return (value / 100);
}

template <PMCurrency::pm_currency_t C>
qint64 PMMoney<C>::get_centum(void) const{
    return (value % 100);
}

template <PMCurrency::pm_currency_t C>
void PMMoney<C>::set_full_value(qint64 centum){
    value = centum;
}

template <PMCurrency::pm_currency_t C>
void PMMoney<C>::set_full_value(qint64 moneta, qint64 centum){
    value = moneta * 100 + centum;
}

template <PMCurrency::pm_currency_t C>
PMCurrency::pm_currency_t PMMoney<C>::get_currency(void) const{
    return C;
}

template <PMCurrency::pm_currency_t C>
QString PMMoney<C>::get_str_currency(void) const{
    QMetaEnum metaEnum = QMetaEnum::fromType<PMCurrency::pm_currency_t>();
    return metaEnum.valueToKey(C);
}

template <PMCurrency::pm_currency_t C>
QDataStream& operator <<(QDataStream& stream, const PMMoney<C>& money){
    return stream << money.get_moneta() << '.' << money.get_centum() << ' '
                  << money.get_str_currency();
}

template <PMCurrency::pm_currency_t C>
PMMoney<C> operator+(const PMMoney<C> &money_l, const PMMoney<C> &money_r){
    if(money_l.currency != money_r.currency){
        throw std::invalid_argument("Addition of different carrency!");
    }
    return PMMoney(money_l.value + money_r.value, money_l.currency);
}

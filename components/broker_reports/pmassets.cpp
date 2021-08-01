#include "pmassets.h"

template <QString& A, PMCurrency::pm_currency_t C>
PMAssets<A,C>::PMAssets():
    PMMoney<C>(),
    number{0}
{}

template <QString& A, PMCurrency::pm_currency_t C>
PMAssets<A,C>::PMAssets(qint64 num, PMMoney<C>& value):
    PMMoney<C>(value.get_value_centum()),
    number{num}
{}

template <QString& A, PMCurrency::pm_currency_t C>
PMMoney<C> PMAssets<A,C>::get_avr_price(void){
    return PMMoney(PMMoney<C>::value / number);
}

template <QString& A, PMCurrency::pm_currency_t C>
qint64 PMAssets<A,C>::get_number(void){
    return number;
}

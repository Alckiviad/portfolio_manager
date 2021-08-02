#include "pmtransaction.h"

template <QString& A, PMCurrency::pm_currency_t C>
PMTransaction<A,C>::PMTransaction():
    PMAssets<A,C>(),
    timestamp(),
    commission()
{}

template <QString& A, PMCurrency::pm_currency_t C>
PMTransaction<A,C>::PMTransaction(const QDateTime& trans_time, qint64 num, const PMMoney<C>& value):
    PMAssets<A,C>(num, value),
    timestamp(trans_time),
    commission(value)
{}

template <QString& A, PMCurrency::pm_currency_t C>
void PMTransaction<A,C>::set_commission(const PMMoney<C>& com){
    commission = com;
}

template <QString& A, PMCurrency::pm_currency_t C>
void PMTransaction<A,C>::set_timestamp(const QDateTime& stamp){
    timestamp = stamp;
}

template <QString& A, PMCurrency::pm_currency_t C>
PMMoney<C> PMTransaction<A,C>::get_commission(void){
    return commission;
}

template <QString& A, PMCurrency::pm_currency_t C>
QDateTime PMTransaction<A,C>::get_timestamp(void){
    return timestamp;
}

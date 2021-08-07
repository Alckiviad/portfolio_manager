#include "pmtransaction.h"
#include <QMessageLogger>

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

PMTransaction_vector::PMTransaction_vector():
    vect()
{}

template <QString& A, PMCurrency::pm_currency_t C>
void PMTransaction_vector::add_transaction(const PMTransaction<A,C>& trans){
    vect.push_back(std::make_tuple(A, C, std::make_any(trans)));
}

QString PMTransaction_vector::get_symbol(int i){
    return std::get<0>(vect[i]);
}

PMCurrency::pm_currency_t PMTransaction_vector::get_trans_curr(int i){
    return std::get<1>(vect[i]);
}

size_t PMTransaction_vector::get_size(void){
    return vect.size();
}

template <QString& A, PMCurrency::pm_currency_t C>
PMTransaction<A,C> PMTransaction_vector::get_transaction(int i){
    return std::any_cast<PMTransaction<A,C>>(std::get<2>(vect[i]));
}


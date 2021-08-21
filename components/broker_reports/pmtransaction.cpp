#include "pmtransaction.h"
#include <QMessageLogger>


PMTransaction::PMTransaction():
    PMAssets(),
    timestamp(),
    commission()
{}


PMTransaction::PMTransaction(const QDateTime& trans_time, const PMMoney& comm, const PMAssets& asset):
    PMAssets(asset),
    timestamp(trans_time),
    commission(comm)
{}

void PMTransaction::set_commission(const PMMoney& com){
    commission = com;
}

void PMTransaction::set_timestamp(const QDateTime& stamp){
    timestamp = stamp;
}

void PMTransaction::set_asset(const PMAssets& new_asset){
    symbol = new_asset.get_symbol();
    number = new_asset.get_number();
    cost   = new_asset.get_cost();
}

PMMoney PMTransaction::get_commission(void)const{
    return commission;
}

QDateTime PMTransaction::get_timestamp(void)const{
    return timestamp;
}

PMAssets PMTransaction::get_asset(void)const{
    return PMAssets(symbol, number, cost);
}

QDebug operator<<(QDebug dbg, const PMTransaction &trans){
    return dbg << "Time:" << trans.timestamp << "Symb:" << trans.symbol
               << "Number:" << trans.number << "Cost:" << trans.cost
               << "Commission:" << trans.commission;
}

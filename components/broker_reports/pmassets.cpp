#include "pmassets.h"


PMAssets::PMAssets():
    number{0},
    cost()
{}

PMAssets::PMAssets(const PMAssets& asset):
    number{asset.number},
    symbol{asset.symbol},
    cost(asset.cost)
{}

PMAssets::PMAssets(QString asset_symbol, qint64 asset_number, PMMoney asset_cost):
    number{asset_number},
    symbol{asset_symbol},
    cost(asset_cost.get_value_centum(),asset_cost.get_currency())
{}

PMMoney PMAssets::get_avr_price(void)const{
    return PMMoney(cost.get_value_centum() / number, cost.get_currency());
}

PMMoney PMAssets::get_cost(void)const{
    return cost;
}

qint64 PMAssets::get_number(void)const{
    return number;
}

QString PMAssets::get_symbol(void)const{
    return symbol;
}

void PMAssets::set_number(const qint64& num){
    number = num;
}

void PMAssets::set_symbol(const QString& symb){
    symbol = symb;
}

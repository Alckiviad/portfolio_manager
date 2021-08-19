#include "pmmoney.h"

PMMoney::PMMoney()
    : value{0},
      m_currency{PMCurrency::USD}
{
}

PMMoney::PMMoney(const PMMoney& money)
    : value{money.value},
      m_currency{money.m_currency}
{
}

PMMoney::PMMoney(qint64 value_centum, PMCurrency::pm_currency_t currency)
    : value{value_centum},
      m_currency{currency}
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

PMCurrency::pm_currency_t PMMoney::get_currency(void) const{
    return m_currency;
}

QString PMMoney::get_str_currency(void) const{
    QMetaEnum metaEnum = QMetaEnum::fromType<PMCurrency::pm_currency_t>();
    return metaEnum.valueToKey(m_currency);
}

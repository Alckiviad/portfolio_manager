#ifndef PMTRANSACTION_H
#define PMTRANSACTION_H

#include "pmassets.h"
#include <QDateTime>

template <QString& A, PMCurrency::pm_currency_t C>
class PMTransaction : public PMAssets<A,C>
{
protected:
    QDateTime timestamp;
    PMMoney<C> commission;
public:
    PMTransaction();
    PMTransaction(const QDateTime& trans_time, qint64 num, const PMMoney<C>& value);

    void set_commission(const PMMoney<C>& com);
    void set_timestamp(const QDateTime& stamp);

    PMMoney<C> get_commission(void);
    QDateTime get_timestamp(void);
};

#endif // PMTRANSACTION_H

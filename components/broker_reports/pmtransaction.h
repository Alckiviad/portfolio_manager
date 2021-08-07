#ifndef PMTRANSACTION_H
#define PMTRANSACTION_H

#include "pmassets.h"
#include <QDateTime>
#include <tuple>
#include <any>

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

class PMTransaction_vector
{
private:
    std::vector<std::tuple<QString, PMCurrency::pm_currency_t, std::any>> vect;
public:
    PMTransaction_vector();

    template <QString& A, PMCurrency::pm_currency_t C>
    void add_transaction(const PMTransaction<A,C>& trans);

    QString get_symbol(int i);
    PMCurrency::pm_currency_t get_trans_curr(int i);
    size_t get_size(void);

    template <QString& A, PMCurrency::pm_currency_t C>
    PMTransaction<A,C> get_transaction(int i);
};

#endif // PMTRANSACTION_H

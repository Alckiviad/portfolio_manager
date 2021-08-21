#ifndef PMTRANSACTION_H
#define PMTRANSACTION_H

#include "pmassets.h"
#include <QDateTime>

class PMTransaction : public PMAssets
{
protected:
    QDateTime timestamp;
    PMMoney commission;
public:
    PMTransaction();
    PMTransaction(const QDateTime& trans_time, const PMMoney& comm, const PMAssets& asset);

    void set_commission(const PMMoney& com);
    void set_timestamp(const QDateTime& stamp);
    void set_asset(const PMAssets& asset);

    PMMoney get_commission(void)const;
    QDateTime get_timestamp(void)const;
    PMAssets  get_asset(void)const;

    friend QDebug operator<<(QDebug dbg, const PMTransaction &trans);
};

#endif // PMTRANSACTION_H

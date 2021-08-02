#ifndef PMASSETS_H
#define PMASSETS_H

#include "pmmoney.h"

template <QString& A, PMCurrency::pm_currency_t C>
class PMAssets : public PMMoney<C>
{
protected:
    qint64 number;
    QString description;
public:
    PMAssets();
    PMAssets(qint64 num, PMMoney<C>& value);

    PMMoney<C> get_avr_price(void);
    qint64 get_number(void);

    void set_number(const qint64& num);
    void set_description(const QString& desc);

    friend PMAssets operator +(PMAssets<A,C>& left,PMAssets<A,C>& right){
        return PMAssets(left.get_number() + right.get_number(),
                        left.get_value_centum() + right.get_value_centum());
    }

    friend PMAssets operator -(PMAssets<A,C>& left,PMAssets<A,C>& right){
        return PMAssets(left.get_number() - right.get_number(),
                        left.get_value_centum() - right.get_value_centum());
    }

    friend QDataStream operator <<(QDataStream& stream, const PMAssets<A,C>& assets){
        return stream << A << " Number: " << assets.get_number() << " Value: "
                      << assets.PMMoney;
    }
};

#endif // PMASSETS_H

#ifndef PMASSETS_H
#define PMASSETS_H

#include "pmmoney.h"

class PMAssets
{
protected:
    qint64  number;
    QString symbol;
    PMMoney cost;
public:
    PMAssets();
    PMAssets(const PMAssets& asset);
    PMAssets(QString asset_symbol, qint64 asset_number, PMMoney asset_cost);

    PMMoney get_avr_price(void)const;
    PMMoney get_cost(void)const;
    qint64 get_number(void)const;
    QString get_symbol(void)const;

    void set_number(const qint64& num);
    void set_symbol(const QString& desc);

    friend PMAssets operator +(PMAssets& left,PMAssets& right){
        if(left.symbol !=right.symbol){
            qCritical() << "Different asset!";
            Q_ASSERT(true);
        }
        return PMAssets(left.symbol, left.number, left.cost + right.cost);
    }

    friend PMAssets operator -(PMAssets& left,PMAssets& right){
        return PMAssets(left.symbol, left.number - right.number,
                        left.cost - right.cost);
    }

    friend QDataStream& operator <<(QDataStream& stream, const PMAssets& assets){
        return stream << assets.symbol << " Number: " << assets.number << " Cost: "
                      << assets.number;
    }
};

#endif // PMASSETS_H

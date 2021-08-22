#include "interactiondb.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
InteractionDB::InteractionDB(QString& name)
{
    dataBaseName_= name;
}

bool InteractionDB::WriteToTradesTable(std::vector<InteractionDB>& object)
{
    //Checking data

    for(auto a : object)
    {
        if()
        {
            qWarning() << "The data set is not correct. Please check your data.\n\nDidn't find <Stocks> key.";
            return false;
        }
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dataBaseName_);

    if(db.isValid())
    {
        qInfo() << "DB is valid";
    } else {
        qWarning() << "DB is not valid. Check DB file.";
    }
    if(db.open())
    {
        qInfo() << "DB is open";
    } else
    {
        qWarning() << "DB is not open... Error: " << db.lastError();

    }
    QSqlQuery query;
    db.open();
    for(auto a : object)
    {
        QString toExec = QString("INSERT INTO Trades VALUES (%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11)").arg(object.get_stoks())
                .arg(object.get_datatime()).arg(object.get_quantity()).arg(object.get_transaction_price()).arg(object.get_close_price())
                .arg(object.get_proceeds()).arg(object.comm_fee()).arg(object.get_basis()).arg(object.get_realized_profit_loss())
                .arg(object.get_mtm_profit_loss()).arg(object.get_code());
        qInfo() << "Prepared command to write: " << toExec << "\n" << a;
        query.prepare(toExec);
        if(!query.exec())
        {
            qWarning() << "Query unsuccesful.";
            db.close();
            return false;
        } else {
            qInfo() << "Query unsuccesful.";
            db.close();
            return true;
        }
    }
}

bool InteractionDB::WriteToFundsTable(std::vector<InteractionDB>& ToWrite)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dataBaseName_);

}

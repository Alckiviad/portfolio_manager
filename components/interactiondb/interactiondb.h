#ifndef INTERACTIONDB_H
#define INTERACTIONDB_H
#include <QtSql/QSql>
#include <QString>
#include <QMap>
/*
 * Class for interaction with database
*/
class InteractionDB
{

    struct new_data_base_Para
    {
      QString path_name;
      QString type_db;
    };
    struct table_to_create
    {
        QList<QString> table_list;
        QVector<QMap<QString, QString>> fields;
    };
public:
    InteractionDB(QString& arg);
    bool WriteToTradesTable(std::vector<InteractionDB>& toWrite);
    bool WriteToFundsTable(std::vector<InteractionDB>& toWrite);
    bool CreateDataBase();
    bool SetNewDataBaseProperties(QString path_name, QString type, QMap<QString, QString> fields);
    template<typename T>
    bool SetQueryRecords (T & records);
private:
    QString dataBaseName_;
};

#endif // INTERACTIONDB_H

#ifndef INTERACTIONDB_H
#define INTERACTIONDB_H
#include <QtSql/QSql>
#include <QString>
#include <map>
/*
 * Class for interaction with database
*/
class interactionDB
{
public:
    interactionDB
    (
           QString data_base_name,
            int regime
            );
    void WriteToDB(std::map<QString, QString> toWrite);
private:
    QString data_base_name;
    int regime;
};

#endif // INTERACTIONDB_H

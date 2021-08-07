#ifndef PMREPORT_PARSER_H
#define PMREPORT_PARSER_H

#include <QtGlobal>
#include <QString>
#include "broker.h"
#include "pmtransaction.h"

class PMReport_parser
{
private:
    QString report_file;
    broker_t broker_type;
public:
    PMReport_parser();

    void set_filename(const QString& name);
    void set_broker(broker_t broker);
    bool check_file(void);
    PMTransaction_vector process_parsing(void);
};

#endif // PMREPORT_PARSER_H

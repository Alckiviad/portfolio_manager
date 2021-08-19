#ifndef PMREPORT_PARSER_H
#define PMREPORT_PARSER_H

#include <QtGlobal>
#include <QString>
#include <vector>
#include "broker.h"
#include "pmtransaction.h"

class PMReport_parser
{
private:
    QString report_file;
    broker_t broker_type;

    bool ib_check_file(void);
    std::vector<PMTransaction> ib_parsing(void);
public:
    PMReport_parser();
    PMReport_parser(const QString& file, broker_t broker);

    void set_filename(const QString& name);
    void set_broker(broker_t broker);
    bool check_file(void);

    std::vector<PMTransaction> process_parsing(void);
};

#endif // PMREPORT_PARSER_H

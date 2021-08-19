#include "pmreport_parser.h"
#include <QFile>
#include <QTextStream>

#define IB_STD_SEP  ','
#define IB_NAME_COL  3
#define IB_NAME      "Interactive Brokers LLC"
#define IB_CURR_COL  4
#define IB_STATE_COL 0
#define IB_HEAD_COL  1
#define IB_SYMB_COL  5
#define IB_COST_COL  9
#define IB_COMM_COL  12
#define IB_NUMB_COL  8
#define IB_TIME_SEP  '"'
#define IB_TIME_COL  1


PMReport_parser::PMReport_parser()
{

}

PMReport_parser::PMReport_parser(const QString& file, broker_t broker):
    report_file(file),
    broker_type(broker)
{
}

void PMReport_parser::set_filename(const QString& name){
    report_file = name;
}

void PMReport_parser::set_broker(broker_t broker){
    broker_type = broker;
}

bool PMReport_parser::ib_check_file(void){
    if(report_file.section('.',1,1) != "csv"){
        qWarning() << "Wrong file's format";
        return false;
    }

    QFile file(report_file);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qWarning() << "File not exists";
        return false;
    }
    QTextStream tstream(&file);

    uint line_numder = 0;
    while (!tstream.atEnd()){
        QString line = tstream.readLine();
        line_numder++;
        if(line_numder == 1) continue;

        if(line_numder == 2){
            QString br_name = line.section(',', IB_NAME_COL, IB_NAME_COL);
            file.close();
            if(IB_NAME == br_name){
                return true;
            }else{
                qWarning() << "Name of the broker didn't found or didn't match";
                return false;
            }
        }
    }
    qWarning() << "Name of the broker didn't found or didn't match";
    file.close();
    return false;
}

bool PMReport_parser::check_file(void){
    if(broker_type == broker_t::IB)
        return ib_check_file();

    return false;
}

std::vector<PMTransaction> PMReport_parser::ib_parsing(void){
    std::vector<PMTransaction> output;

    QFile file(report_file);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qWarning() << "file.open fail!";
        return output;
    }

    QTextStream tstream(&file);

    while (!tstream.atEnd()){
        QString line = tstream.readLine();

        // Trades parsing
        if(line.section(IB_STD_SEP, IB_STATE_COL, IB_STATE_COL) == "Trades"){
            if(line.section(IB_STD_SEP, IB_HEAD_COL, IB_HEAD_COL) == "Data"){
                qDebug() << line;
                QString currency_str = line.section(',', IB_CURR_COL, IB_CURR_COL);
                QByteArray currency_ba = currency_str.toLocal8Bit();
                const char *currency_char = currency_ba.data();
                QMetaEnum metaEnum = QMetaEnum::fromType<PMCurrency::pm_currency_t>();
                int currency_code = metaEnum.keyToValue(currency_char);
                if(currency_code == -1){
                    qWarning() << "Unsupported currency_code";
                    file.close();
                    return output;
                }
                PMCurrency::pm_currency_t currency = (PMCurrency::pm_currency_t)currency_code;

                const QString symbol = line.section(IB_STD_SEP, IB_SYMB_COL, IB_SYMB_COL);

                QDateTime time_stamp;
                time_stamp.setTimeSpec(Qt::TimeSpec::UTC);
                QString date_time = line.section(IB_TIME_SEP, IB_TIME_COL, IB_TIME_COL);

                QString date = date_time.section(',', 0, 0);
                QString day = date.section('-', 2, 2);
                QString month = date.section('-', 1, 1);
                QString year = date.section('-', 0, 0);
                time_stamp.setDate(QDate(year.toInt(), month.toInt(), day.toInt()));

                QString time = date_time.section(',', 1, 1);
                QString sec = time.section(':', 2, 2);
                QString min = time.section(':', 1, 1);
                QString hour = time.section(':', 0, 0);
                time_stamp.setTime(QTime(hour.toInt(), min.toInt(), sec.toInt()));

                QString cost_str = line.section(IB_STD_SEP, IB_COST_COL, IB_COST_COL);
                QString moneta_str = cost_str.section('.', 0, 0);
                QString centum_str = cost_str.section('.', 1, 1);
                quint64 moneta = moneta_str.toUInt();
                quint64 centum = centum_str.toUInt();
                PMMoney cost(moneta*100 + centum, currency);

                QString number_str = line.section(IB_STD_SEP, IB_NUMB_COL, IB_NUMB_COL);
                quint64 number = number_str.toUInt();

                PMAssets asset(symbol, number, cost);

                QString commission_str= line.section(IB_STD_SEP, IB_COMM_COL, IB_COMM_COL);
                float commission_fl = commission_str.toFloat() * 100;
                quint64 commission = 0 - commission_fl / 1;
                PMMoney commiss(commission, currency);

                PMTransaction trans(time_stamp, commiss, asset);
                output.push_back(trans);
            }
        }

    }
    return output;
}

std::vector<PMTransaction> PMReport_parser::process_parsing(void){
    std::vector<PMTransaction> output;

    if(!check_file()){
        qWarning() << "check_file() return false";
        return output;
    }
    qDebug() << "check_file() pass";

    if(broker_type == broker_t::IB){
        return ib_parsing();
    } else {
        qWarning() << "broker_type not supporting";
    }

    return output;
}

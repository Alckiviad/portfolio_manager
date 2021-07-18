#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QBuffer>
#include "../components/broker_reports/broker_reports.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void load_broker_file();

    void on_brokerbox_activated(int index);

private:
    Ui::MainWindow *ui;
    broker_t broker_box;
};
#endif // MAINWINDOW_H

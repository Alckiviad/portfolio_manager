#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageLogger>
#include "../components/broker_reports/broker_reports.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->import_button, &QPushButton::clicked,
            this, &MainWindow::load_broker_file);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::load_broker_file()
{
    qDebug() << "load_broker_file...";
    QString fileName = QFileDialog::getOpenFileName(0, QString(), QString(),
                                        tr("Reports (*)"));
    if(!fileName.isEmpty()){
        qDebug() << "File Name - " << fileName;
    } else {
        qDebug() << "File name is empty";
    }

}


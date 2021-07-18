#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageLogger>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->import_button, &QPushButton::clicked,
            this, &MainWindow::load_broker_file);

    connect(ui->brokerbox, &QComboBox::currentIndexChanged,
            this, &MainWindow::on_brokerbox_activated);
    MainWindow::broker_box = TINKOFF;

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

void MainWindow::on_brokerbox_activated(int index)
{
    qDebug() << "broker box " << index;

    switch (index) {
        case 0:
            MainWindow::broker_box = TINKOFF;
            break;
        case 1:
            MainWindow::broker_box = IB;
            break;
        default:
            qCritical() << "Unexpected index of brokerbox: " << index;
    }
}


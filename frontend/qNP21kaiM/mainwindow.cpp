#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     if(!api.load()) {
        return;
    }
    int argc = QApplication::arguments().length() ;
    char **argv = new char*[argc+ 1];
    for(int i = 0; i < argc; i++) {
        argv[i] = QApplication::arguments().at(i).toUtf8().data();
        argv[i+1] = NULL;
    }

    api.np2api_main(argc, argv, (void*)ui->np2widget->winId());

    delete []argv;

    timer = new QTimer();

    connect(timer, &QTimer::timeout, this, &MainWindow::idle);
    timer->start(0);
}

MainWindow::~MainWindow()
{
    timer->stop();
    api.unload();
    api.np2api_end();

    delete ui;
}

void MainWindow::idle()
{
    api.np2api_exec();
}

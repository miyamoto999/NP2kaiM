#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "kbddrv.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();

    if(!api.load()) {
        QMessageBox::critical(this, "qNP2kaiM", tr("Could not load Core DLL."));
        return;
    }
    int argc = QApplication::arguments().length() ;
    char **argv = new char*[argc+ 1];
    for(int i = 0; i < argc; i++) {
        argv[i] = QApplication::arguments().at(i).toUtf8().data();
    }
    argv[argc - 1] = NULL;

    api.np2api_main(argc, argv, (void*)ui->np2widget->winId());

    delete []argv;

    connect(timer, &QTimer::timeout, this, &MainWindow::idle);
    timer->start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::idle()
{
    api.np2api_exec();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
#ifdef Q_OS_MACOS
    quint8 keycode98 = KbdDrv::keycodeTransrate(event->nativeVirtualKey());
#else
    quint8 keycode98 = KbdDrv::keycodeTransrate(event->nativeScanCode());
#endif
    if(keycode98 == KEYCODE98_NC) {
        return;
    }
    api.np2api_keydown(keycode98);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
#ifdef Q_OS_MACOS
    quint8 keycode98 = KbdDrv::keycodeTransrate(event->nativeVirtualKey());
#else
    quint8 keycode98 = KbdDrv::keycodeTransrate(event->nativeScanCode());
#endif
    if(keycode98 == KEYCODE98_NC) {
        return;
    }
    api.np2api_keyup(keycode98);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    timer->stop();
    api.unload();
    api.np2api_end();
}


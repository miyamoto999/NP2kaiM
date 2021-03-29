#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "np2kaiapi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    NP2kaiapi api;
    QTimer *timer = NULL;

private slots:
    void idle();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

};
#endif // MAINWINDOW_H

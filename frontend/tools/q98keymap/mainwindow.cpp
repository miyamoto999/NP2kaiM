/**
 * @brief メインウィンドウクラス
 *
 *　メインウィンドウクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      メインウィンドウクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keydata.h"
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include "inputkeydialog.h"
#include "keydialog.h"

/**
 * @brief コンストラクタ
 * @details
 *  コンストラクタ
 *
 * @param[in] 	parent 	親ウィジェット
 *
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createMenu();

    connect(ui->keyWidget, &KeyWidget::KeymapClick, this, &MainWindow::OnKeymapClick);
}

/**
 * @brief デストラクタ
 * @details
 *  デストラクタ
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief キープレスイベント処理
 * @details
 *      キーコードの表示、キーコードが設定されているキーの色を更新する。
 *
 * @param[in] 	   event      キープレスイベントパラメータ
 *
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->labelKey->setText("0x" + QString::number(event->key(), 16));
    ui->labelModifiers->setText("0x" + QString::number(event->modifiers(), 16));
    ui->labelNativeModifiers->setText("0x" + QString::number(event->nativeModifiers(), 16));
    ui->labelNativeScanCode->setText("0x" + QString::number(event->nativeScanCode(), 16));
    ui->labelNativeVirtualKey->setText("0x" + QString::number(event->nativeVirtualKey(), 16));

    keydatas_keydown(event->key());
    update();
}

/**
 * @brief キーリリースイベント処理
 * @details
 *      キーコードが設定されているキーの色を元に戻す。
 *
 * @param[in] 	   event      キーリリースイベントパラメータ
 *
 */
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    keydatas_keyup(event->key());
    update();
}

/**
 * @brief KeyWidgetクリックイベント処理
 * @details
 *      KeyWidetで表示されるキーをクリックした時に発生するシグナルを
 *      受けるスロット。キー表示ダイアログを表示し、キーが更新されたら
 *      キーデータ配列の対象キーのキーデータを更新する。
 *
 * @param[in] 	   index      クリックされたキーのキーデータ配列インデックス
 *
 */
void MainWindow::OnKeymapClick(int index)
{
    qDebug() << "index:" << index;

    KeyDialog dlg(this, keydatas[index]);
    if(dlg.exec() == QDialog::Accepted) {
        qDebug() << "KeyDialog accepted";
        KEYDATA data = dlg.getKeydata();
        if(dlg.getDeleteKeyBinding()) {
            data.flag = 0;
        } else {
            data.flag |= KEYDATA_HAVE_DATA;
        }
        keydatas_keydataupdate(keydatas[index].keyname, data);
        update();
    }
}

/**
 * @brief メニュー生成
 * @details
 *      メニューを生成する。
 */
void MainWindow::createMenu()
{
    // fileメニュー
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    // 開く
    const QIcon openIcon = QIcon::fromTheme("document-open"  /*, QIcon(":/images/open.png") */);
    QAction *actionOpen = new QAction(openIcon, tr("&Open..."), this);
    actionOpen->setShortcuts(QKeySequence::Open);
    actionOpen->setStatusTip(tr("Open file"));
    connect(actionOpen, &QAction::triggered, this, &MainWindow::menuOpen);
    fileMenu->addAction(actionOpen);

    // 保存
    const QIcon saveIcon = QIcon::fromTheme("document-save" /*, QIcon(":/images/save.png")*/);
    QAction *actionSave = new QAction(saveIcon, tr("&Save"), this);
    actionSave->setShortcuts(QKeySequence::Save);
    actionSave->setStatusTip(tr("Save the file as"));
    connect(actionSave, &QAction::triggered, this, &MainWindow::menuSave);
    fileMenu->addAction(actionSave);

    // 名前をつけて保存
    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as" /*, QIcon(":/images/saveas.png")*/);
    QAction *actionSaveAs = new QAction(saveAsIcon, tr("Save &As..."), this);
    actionSaveAs->setShortcuts(QKeySequence::SaveAs);
    actionSaveAs->setStatusTip(tr("Save the file as"));
    connect(actionSaveAs, &QAction::triggered, this, &MainWindow::menuSaveAs);
    fileMenu->addAction(actionSaveAs);

    // 閉じる
    QAction *actionClose = new QAction(tr("&Close"), this);
    actionClose->setShortcut(QKeySequence::Close);
    actionClose->setStatusTip(tr("Close file"));
    connect(actionClose, &QAction::triggered, this, &MainWindow::menuClose);
    fileMenu->addAction(actionClose);

#ifndef Q_OS_MACOS
    // 終了
    QAction *actionQuit = new QAction(tr("&Quit"), this);
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit Application"));
    connect(actionQuit, &QAction::triggered, this, &MainWindow::menuQuit);
    fileMenu->addAction(actionQuit);
#endif
}

/**
 * @brief メニューの開くを選択されたときの処理
 * @details
 *      ファイルオープンダイアログを表示し、選択されたファイルを読み込む。
 *
 */
void MainWindow::menuOpen()
{
    if(keydatas_update) {
        if(QMessageBox::question(this, tr("Open"), tr("Your changes have not been saved yet.\nAre you sure?")) == QMessageBox::No) {
            return;
        }
    }
    QString filename = QFileDialog::getOpenFileName(this, tr("Open"),
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                    tr("Text file(*.txt)"));
    if(!filename.isEmpty()) {
        keydatas_clearData();
        m_openFilename = QString();
        if(!keydatas_openFile(filename)) {
            QMessageBox::about(this, tr("Open"), tr("File Open ERROR"));
            keydatas_clearData();
       } else {
            m_openFilename = filename;
        }
        update();
    }
}

/**
 * @brief メニューの保存を選択されたときの処理
 * @details
 *      ファイルを読み込んでいる場合は、読み込んだファイル名で上書き保存し、
 *      読み込んでない場合は、名前を付けて保存ダイアログを表示し、入力されたファイル名で
 *      保存する。
 *
 */
void MainWindow::menuSave()
{
    if(m_openFilename.isEmpty()) {
        menuSaveAs();
    } else {
        if(!keydatas_saveFile(m_openFilename)) {
            QMessageBox::about(this, tr("Save"), tr("File save ERROR"));
        } else {
            keydatas_update = false;
        }
    }
}

/**
 * @brief メニューの名前を付けて保存を選択されたときの処理
 * @details
 *      名前を付けて保存ダイアログを表示し、入力されたファイル名で保存する。
 *
 */
void MainWindow::menuSaveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                    tr("Text file(*.txt)"));
    if(!filename.isEmpty()) {
       if(!keydatas_saveFile(filename)) {
           QMessageBox::about(this, tr("Save As"), tr("File save ERROR"));
       } else {
           m_openFilename = filename;
           keydatas_update = false;
       }
    }
}

/**
 * @brief メニューの閉じるを選択されたときの処理
 * @details
 *      データを初期化する。
 *
 */
void MainWindow::menuClose()
{
    if(keydatas_update) {
        if(QMessageBox::question(this, tr("Open"), tr("Your changes have not been saved yet.\nAre you sure?")) == QMessageBox::No) {
            return;
        }
    }
    keydatas_clearData();
    m_openFilename = QString();
    update();
}

/**
 * @brief メニューの終了を選択されたときの処理
 * @details
 *      ウィンドウを閉じる。メインウィンドウなのでアプリケーション終了する。
 *
 */
void MainWindow::menuQuit()
{
    this->close();
}

/**
 * @brief ウィンドウを閉じようとしたときのイベント処理
 * @details
 *      データ更新されていて、ファイルに保存されていない時は、保存していないことを
 *      表示し、それでも終了していい場合は終了するようにする。
 *
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(keydatas_update) {
        if(QMessageBox::question(this, tr("Open"), tr("Your changes have not been saved yet.\nAre you sure?")) == QMessageBox::No) {
            event->ignore();
            return;
        }
        event->accept();
    }
}


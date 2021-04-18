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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
* @brief メインウィンドウクラス
* @details
*       メインウィンドウクラス
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // コンストラクタ
    MainWindow(QWidget *parent = nullptr);
    // デストラクタ
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // メニューの生成
    void createMenu();
    // メニューの開くを選択された時の処理
    void menuOpen();
    // メニューの保存を選択されたときの処理
    void menuSave();
    // メニューの名前を付けて保存を選択されたときの処理
    void menuSaveAs();
    // メニューの閉じるを選択されたときの処理
    void menuClose();
    // メニューの終了を選択されたときの処理
    void menuQuit();

    /**
    * オープンしているファイル名
    */
    QString m_openFilename;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void OnKeymapClick(int index);

};
#endif // MAINWINDOW_H

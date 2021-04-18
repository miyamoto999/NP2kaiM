/**
 * @brief main関数
 *
 * main関数
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

/**
 * @brief main関数
 * @details
 *     いろいろ初期化してメインウィンドウを表示する。
 *
 * @param[in] 	    argc      	コマンドライン引数の数
 * @param[in]       argv          コマンドライン引数
 * @retval 0    正常終了
 *
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    QTranslator appTranslator;
    QString locale = QLocale::system().bcp47Name();

#ifdef Q_OS_MACOS
    // 日本語の漢字が正しく表示されないので
    // 日本語フォントを設定する。Osakaが適当かどうかは不明
    if(locale == "ja") {
        QFont font("Osaka");
        a.setFont(font);
    }
#endif
    // macOSのアプリケーションメニューなどに組み込まれている
    // メッセージをローカライズするようにリソースを読み込む。
   if(appTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath))) {
       a.installTranslator(&appTranslator);
   }

   // このアプリケーションの ローカライズファイルを読み込む
    if(translator.load(":/i18n/q98keymap_" + locale + ".qm")) {
        a.installTranslator(&translator);
    }
    MainWindow w;
    w.show();
    return a.exec();
}

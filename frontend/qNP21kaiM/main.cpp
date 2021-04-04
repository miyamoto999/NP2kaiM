#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

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

   // このアプリケーションの ローカライズファイルをファイルを読み込む
    if(translator.load(":/i18n/qNP21kaiM_" + locale + ".qm")) {
        a.installTranslator(&translator);
    }

   MainWindow w;
    w.show();
    return a.exec();
}

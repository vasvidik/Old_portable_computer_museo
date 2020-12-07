#include <QtGui/QApplication>
#include <QTextCodec>
#include <QString>
#include "mainwindow.h"
#include "devicelist.h"

int global_year;
QString global_devicetype;

int main(int argc, char *argv[])
{

    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

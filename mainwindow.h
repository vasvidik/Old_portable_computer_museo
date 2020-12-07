#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "devicelist.h"
#include <string.h>
#include <QtXml/QXmlStreamReader>
#define FINISH_YEAR 2010
#define START_YEAR 1980

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    char devicetype;     // DON'T DELETE THIS VALUE!!!!

    bool availability_of_device[FINISH_YEAR-START_YEAR+1][6];       // 0 - c; 1 - n; 2 - h; 3 - p; 4 - u; 5 - s.
    QXmlStreamReader start_xml;
    QFile start_file;

private slots:


    void on_timeline_valueChanged(int value);

    void on_button_calc_clicked();

    void on_button_notebook_clicked();

    void on_button_hpc_clicked();

    void on_button_pda_clicked();

    void on_button_umpc_clicked();

    void on_button_smartphone_clicked();

    void devicelist_show();

    void start_checking_device();

    void start_reading_type_and_year_of_device();




private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H

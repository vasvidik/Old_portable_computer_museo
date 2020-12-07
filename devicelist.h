#ifndef DEVICELIST_H
#define DEVICELIST_H

#include <QDialog>
#include "mainwindow.h"
#include <QFile>
#include <QtXml/QXmlStreamReader>
#include <QListWidgetItem>

namespace Ui {
class DeviceList;
}

class DeviceList : public QDialog
{
    Q_OBJECT
    
public:
    //explicit DeviceList(QWidget *parent = 0, int year, char devicetype);
    explicit DeviceList(QWidget *parent = 0);
    ~DeviceList();
    QFile m_file;
    QXmlStreamReader m_xml;


    int w, h;

public slots:

    void reading_type_and_year_of_device();
    void checking_device();
//    void reading_year_of_device();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::DeviceList *ui;


};


#endif // DEVICELIST_H


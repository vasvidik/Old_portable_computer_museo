#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "devicelist.h"
#include <QtGui>
#include <QtSql/QtSql>
#include <QtXml/QtXml>
#include <QFile>
#include <QtXml/QXmlStreamReader>

extern int global_year;
extern QString global_devicetype;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timeline->setValue(START_YEAR);
    global_year = ui->timeline->value();
    ui->label->setText(QString::number(START_YEAR));
    ui->label_2->setText(QString::number(FINISH_YEAR));
    ui->timeline->setMinimum(START_YEAR);
    ui->timeline->setMaximum(FINISH_YEAR);
    ui->timeSpinbox->setMinimum(START_YEAR);
    ui->timeSpinbox->setMaximum(FINISH_YEAR);
    ui->button_umpc->setEnabled(false);
    ui->button_calc->setEnabled(true);
    ui->button_smartphone->setEnabled(false);

	for(unsigned int mass_year = 0;mass_year < (FINISH_YEAR-START_YEAR+1); mass_year++)
	{
		for(unsigned int mass_type = 0;mass_type < 6; mass_type++)
		availability_of_device[mass_year][mass_type] = false;
	}



    start_file.setFileName("mus.xml");
    if(!start_file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,QString("Not open xml file!"),QString("Not open xml file!"));
    }



    start_xml.setDevice(&start_file);



    start_xml.readNext();
    while(!start_xml.atEnd())
    {
        if(start_xml.isStartElement())
        {
            if(start_xml.name() == "devices")
            {
                start_checking_device();
            }
            else
            {
                start_xml.raiseError("error of reading");
            }
        }
        else
        {
            start_xml.readNext();
        }
    }

    start_file.close();

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_timeline_valueChanged(int value)
{

    global_year = ui->timeline->value();

	ui->button_calc->setEnabled(availability_of_device[FINISH_YEAR-value+1][0]);
	ui->button_notebook->setEnabled(availability_of_device[FINISH_YEAR-value+1][1]);
	ui->button_hpc->setEnabled(availability_of_device[FINISH_YEAR-value+1][2]);
	ui->button_pda->setEnabled(availability_of_device[FINISH_YEAR-value+1][3]);
	ui->button_umpc->setEnabled(availability_of_device[FINISH_YEAR-value+1][4]);
	ui->button_smartphone->setEnabled(availability_of_device[FINISH_YEAR-value+1][5]);


}


void MainWindow::start_checking_device()
{
    start_xml.readNext();
    while(start_xml.name() != "theEnd")
    {
        if(start_xml.name() == "device")
        {
            start_reading_type_and_year_of_device();
        }
        else
        {
        }
        start_xml.readNext();
    }

}

void MainWindow::start_reading_type_and_year_of_device()
{
    start_xml.readNext();

    while(start_xml.name() != "year")
    {
        start_xml.readNext();
    }
    QString start_xml_year_string = start_xml.readElementText();
    int start_xml_year_int = (start_xml_year_string).toInt();


    start_xml.readNext();
    while(start_xml.name() != "id")
    {
        start_xml.readNext();
    }

    QString start_xml_device_id = start_xml.readElementText();
    char start_xml_device_type_char = start_xml_device_id.at(0).toAscii();

	switch(start_xml_device_type_char) // 0 - c; 1 - n; 2 - h; 3 - p; 4 - u; 5 - s.
	{
		case 'c':
			start_xml_device_type_char = 0;
			break;
		case 'n':
			start_xml_device_type_char = 1;
			break;
		case 'h':
			start_xml_device_type_char = 2;
			break;
		case 'p':
			start_xml_device_type_char = 3;
			break;
		case 'u':
			start_xml_device_type_char = 4;
			break;
		case 's':
			start_xml_device_type_char = 5;
			break;
		default:
			break;
    }

	availability_of_device[FINISH_YEAR-start_xml_year_int+1][start_xml_device_type_char] = true;

    start_xml.skipCurrentElement();
    return;
}


void MainWindow::devicelist_show()
{
    //DeviceList listdialog((QWidget *)this, year, devicetype);

    DeviceList listdialog(this);

    listdialog.setModal(true);
    listdialog.resize(280, 300);


	switch(global_devicetype.at(0).toAscii())
    {
        case 'c':
            listdialog.setWindowTitle(tr("Программуируемые калькуляторы ")+QString::number(global_year)+tr(" года"));
            break;
        case 'n':
            listdialog.setWindowTitle(tr("Ноутбуки ")+QString::number(global_year)+tr(" года"));
            break;
        case 'h':
            listdialog.setWindowTitle(tr("Handheld PC ")+QString::number(global_year)+tr(" года"));
            break;
        case 'p':
            listdialog.setWindowTitle(tr("КПК ")+QString::number(global_year)+tr(" года"));
            break;
        case 'u':
            listdialog.setWindowTitle(tr("UMPC ")+QString::number(global_year)+tr(" года"));
            break;
        case 's':
            listdialog.setWindowTitle(tr("Смартфоны ")+QString::number(global_year)+tr(" года"));
            break;
        default:
            break;
    }

    listdialog.exec();

}

void MainWindow::on_button_calc_clicked()
{
    global_devicetype = 'c';
    devicelist_show();
}

void MainWindow::on_button_notebook_clicked()
{
    global_devicetype = 'n';
    devicelist_show();
}

void MainWindow::on_button_hpc_clicked()
{
    global_devicetype = 'h';
    devicelist_show();
}

void MainWindow::on_button_pda_clicked()
{
    global_devicetype = 'p';
    devicelist_show();
}

void MainWindow::on_button_umpc_clicked()
{
    global_devicetype = 'u';
    devicelist_show();

}

void MainWindow::on_button_smartphone_clicked()
{
    global_devicetype = 's';
    devicelist_show();
}


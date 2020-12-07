#include "devicelist.h"
#include "ui_devicelist.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>
#include <QTextStream>
#include <QTextCodec>

extern int global_year;
extern QString global_devicetype;

//DeviceList::DeviceList(QWidget *parent, int year, char devicetype) :
DeviceList::DeviceList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceList)
{
    ui->setupUi(this);
    w = 300;
    h = 281;


    m_file.setFileName("mus.xml");
    if(!m_file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,QString("Not open xml file!"),QString("Not open xml file!"));
    }

    m_xml.setDevice(&m_file);



    m_xml.readNext();
    while(!m_xml.atEnd())
    {
        if(m_xml.isStartElement())
        {
            if(m_xml.name() == "devices")
            {
                checking_device();
            }
            else
            {
                m_xml.raiseError("error of reading");
            }
        }
        else
        {
            m_xml.readNext();
        }
    }





}

DeviceList::~DeviceList()
{
    m_file.close();
    delete ui;
}

void DeviceList::checking_device()
{
    m_xml.readNext();
    while(m_xml.name() != "theEnd")
    {
        if(m_xml.name() == "device")
        {
            reading_type_and_year_of_device();
        }
        else
        {
        }
        m_xml.readNext();
    }

}

void DeviceList::reading_type_and_year_of_device()
{
    m_xml.readNext();

    while(m_xml.name() != "year")
    {
        m_xml.readNext();
    }
    QString xml_year_string = m_xml.readElementText();
    QString m_year_string = QString::number(global_year);

    if(xml_year_string.contains(m_year_string));
    else
    {
        m_xml.skipCurrentElement();
        return;
    }

    m_xml.readNext();
    while(m_xml.name() != "id")
    {
        m_xml.readNext();
    }

    QString xml_device_id = m_xml.readElementText();

    if(xml_device_id.contains(global_devicetype));
    else
    {
        m_xml.skipCurrentElement();
        return;
    }

    m_xml.readNext();
    while(m_xml.name() != "name")
    {
        m_xml.readNext();
    }



    QString xml_device_name = m_xml.readElementText();
    ui->listWidget->addItem(xml_device_name);

    /*

    m_xml.readNext();
    while(m_xml.name() != "text_about")
    {
        m_xml.readNext();
    }

    QString xml_text_about_device = m_xml.readElementText();
    text_about_devices.append(xml_text_about_device);

    */

    m_xml.skipCurrentElement();
    return;
}


void DeviceList::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString item_name = item->text();
    QPixmap item_pixmap = QPixmap( QString("images/") + item_name + QString(".jpg"));
    int image_w = item_pixmap.width();
    int image_h = item_pixmap.height();
    double image_size = (double)image_w/(double)image_h;
    ui->label->setPixmap(item_pixmap);

    if(image_w>image_h)
        ui->label->resize(w, (int)(h/image_size));
    else
    {
        image_size = (double)image_h/(double)image_w;
        ui->label->resize((int)(w/image_size), h);
    }


    ui->label->setScaledContents(true);
    ui->label->show();

    /*
    int number = ui->listWidget->currentRow();
    ui->Edit_about_device->setText(text_about_devices[number]);
    */

    QString name_html = QString("texts/") + item_name + QString(".html");



    QFile html_file(name_html);

    if(!html_file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,QString("Not open html file!"),QString("Not open html file!"));
    }

    QTextStream stream (&html_file);
    stream.setCodec(QTextCodec::codecForName("UTF-8"));

    QString html_about = stream.readAll();
    //ui->Edit_about_device->setText(html_about);


    ui->Edit_about_device->setHtml(html_about);
    //ui->Edit_about_device->append(html_file);


    resize(591, 491);
}

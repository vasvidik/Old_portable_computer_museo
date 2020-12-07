/********************************************************************************
** Form generated from reading UI file 'devicelist.ui'
**
** Created: Mon 20. Jul 15:20:50 2020
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICELIST_H
#define UI_DEVICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DeviceList
{
public:
    QListWidget *listWidget;
    QTextEdit *Edit_about_device;
    QLabel *label;

    void setupUi(QDialog *DeviceList)
    {
        if (DeviceList->objectName().isEmpty())
            DeviceList->setObjectName(QString::fromUtf8("DeviceList"));
        DeviceList->resize(591, 491);
        DeviceList->setMinimumSize(QSize(280, 300));
        DeviceList->setMaximumSize(QSize(591, 491));
        DeviceList->setProperty("device_year", QVariant(1965));
        listWidget = new QListWidget(DeviceList);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 260, 280));
        Edit_about_device = new QTextEdit(DeviceList);
        Edit_about_device->setObjectName(QString::fromUtf8("Edit_about_device"));
        Edit_about_device->setGeometry(QRect(10, 300, 571, 181));
        Edit_about_device->setReadOnly(true);
        label = new QLabel(DeviceList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 10, 301, 281));

        retranslateUi(DeviceList);

        QMetaObject::connectSlotsByName(DeviceList);
    } // setupUi

    void retranslateUi(QDialog *DeviceList)
    {
        DeviceList->setWindowTitle(QApplication::translate("DeviceList", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeviceList: public Ui_DeviceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICELIST_H

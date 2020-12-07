/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 14. Jul 19:31:28 2020
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *timeline;
    QSpinBox *timeSpinbox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_notebook;
    QPushButton *button_pda;
    QPushButton *button_smartphone;
    QPushButton *button_hpc;
    QPushButton *button_calc;
    QPushButton *button_umpc;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 300);
        MainWindow->setMinimumSize(QSize(600, 300));
        MainWindow->setMaximumSize(QSize(600, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        timeline = new QSlider(centralWidget);
        timeline->setObjectName(QString::fromUtf8("timeline"));
        timeline->setGeometry(QRect(25, 50, 550, 15));
        timeline->setMinimum(1965);
        timeline->setMaximum(2010);
        timeline->setOrientation(Qt::Horizontal);
        timeSpinbox = new QSpinBox(centralWidget);
        timeSpinbox->setObjectName(QString::fromUtf8("timeSpinbox"));
        timeSpinbox->setGeometry(QRect(270, 10, 60, 25));
        timeSpinbox->setMinimum(1965);
        timeSpinbox->setMaximum(2010);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 30, 35, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(550, 30, 35, 15));
        button_notebook = new QPushButton(centralWidget);
        button_notebook->setObjectName(QString::fromUtf8("button_notebook"));
        button_notebook->setEnabled(false);
        button_notebook->setGeometry(QRect(310, 80, 250, 50));
        button_pda = new QPushButton(centralWidget);
        button_pda->setObjectName(QString::fromUtf8("button_pda"));
        button_pda->setEnabled(false);
        button_pda->setGeometry(QRect(310, 140, 250, 50));
        button_smartphone = new QPushButton(centralWidget);
        button_smartphone->setObjectName(QString::fromUtf8("button_smartphone"));
        button_smartphone->setEnabled(false);
        button_smartphone->setGeometry(QRect(310, 200, 250, 50));
        button_hpc = new QPushButton(centralWidget);
        button_hpc->setObjectName(QString::fromUtf8("button_hpc"));
        button_hpc->setEnabled(false);
        button_hpc->setGeometry(QRect(40, 140, 250, 50));
        button_calc = new QPushButton(centralWidget);
        button_calc->setObjectName(QString::fromUtf8("button_calc"));
        button_calc->setGeometry(QRect(40, 80, 250, 50));
        button_umpc = new QPushButton(centralWidget);
        button_umpc->setObjectName(QString::fromUtf8("button_umpc"));
        button_umpc->setEnabled(false);
        button_umpc->setGeometry(QRect(40, 200, 250, 50));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(timeline, SIGNAL(valueChanged(int)), timeSpinbox, SLOT(setValue(int)));
        QObject::connect(timeSpinbox, SIGNAL(valueChanged(int)), timeline, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\321\203\320\267\320\265\320\271 \320\277\320\276\321\200\321\202\320\260\321\202\320\270\320\262\320\275\320\276\320\271 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "1965", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "2010", 0, QApplication::UnicodeUTF8));
        button_notebook->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\203\321\202\320\261\321\203\320\272\320\270", 0, QApplication::UnicodeUTF8));
        button_pda->setText(QApplication::translate("MainWindow", "\320\232\320\237\320\232", 0, QApplication::UnicodeUTF8));
        button_smartphone->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\260\321\200\321\202\321\204\320\276\320\275\321\213", 0, QApplication::UnicodeUTF8));
        button_hpc->setText(QApplication::translate("MainWindow", "Handheld PC", 0, QApplication::UnicodeUTF8));
        button_calc->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\321\203\320\265\320\274\321\213\320\265 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        button_umpc->setText(QApplication::translate("MainWindow", "UMPC", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

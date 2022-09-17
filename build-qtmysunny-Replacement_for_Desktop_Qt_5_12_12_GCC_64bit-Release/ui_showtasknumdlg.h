/********************************************************************************
** Form generated from reading UI file 'showtasknumdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTASKNUMDLG_H
#define UI_SHOWTASKNUMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_showtasknumdlg
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *labelshow;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *showtasknumdlg)
    {
        if (showtasknumdlg->objectName().isEmpty())
            showtasknumdlg->setObjectName(QString::fromUtf8("showtasknumdlg"));
        showtasknumdlg->resize(929, 738);
        label = new QLabel(showtasknumdlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 161, 17));
        tableWidget = new QTableWidget(showtasknumdlg);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(6, 2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(7, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(8, 2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(9, 2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(10, 2, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setItem(11, 2, __qtablewidgetitem50);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 60, 301, 551));
        tableWidget->verticalHeader()->setVisible(false);
        labelshow = new QLabel(showtasknumdlg);
        labelshow->setObjectName(QString::fromUtf8("labelshow"));
        labelshow->setGeometry(QRect(340, 60, 571, 661));
        label_2 = new QLabel(showtasknumdlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 640, 61, 17));
        label_3 = new QLabel(showtasknumdlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 670, 101, 17));
        label_4 = new QLabel(showtasknumdlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 700, 67, 17));

        retranslateUi(showtasknumdlg);

        QMetaObject::connectSlotsByName(showtasknumdlg);
    } // setupUi

    void retranslateUi(QDialog *showtasknumdlg)
    {
        showtasknumdlg->setWindowTitle(QApplication::translate("showtasknumdlg", "Dialog", nullptr));
        label->setText(QApplication::translate("showtasknumdlg", "\344\273\273\345\212\241\345\217\267\345\233\276\347\244\272:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("showtasknumdlg", "\344\273\273\345\212\241\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("showtasknumdlg", "\346\241\206\346\236\266\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("showtasknumdlg", "\350\257\206\345\210\253\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem14->setText(QApplication::translate("showtasknumdlg", "Task:", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("showtasknumdlg", "0-99", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("showtasknumdlg", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(0, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("showtasknumdlg", "\351\235\236\346\234\254\350\275\257\344\273\266\346\241\206\346\236\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("showtasknumdlg", "100", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("showtasknumdlg", "\345\206\205\350\247\222\347\274\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("showtasknumdlg", "101", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("showtasknumdlg", "\345\244\226\350\247\222\347\274\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("showtasknumdlg", "102", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("showtasknumdlg", "Z\350\247\222\346\263\242\347\272\271\346\235\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(4, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("showtasknumdlg", "103", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(4, 1);
        ___qtablewidgetitem28->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(4, 2);
        ___qtablewidgetitem29->setText(QApplication::translate("showtasknumdlg", "\350\275\256\345\273\223\346\243\200\346\265\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(5, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("showtasknumdlg", "104", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(5, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(5, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(6, 0);
        ___qtablewidgetitem33->setText(QApplication::translate("showtasknumdlg", "105", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(6, 1);
        ___qtablewidgetitem34->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(6, 2);
        ___qtablewidgetitem35->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(7, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("showtasknumdlg", "106", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(7, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(7, 2);
        ___qtablewidgetitem38->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(8, 0);
        ___qtablewidgetitem39->setText(QApplication::translate("showtasknumdlg", "107", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(8, 1);
        ___qtablewidgetitem40->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(8, 2);
        ___qtablewidgetitem41->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(9, 0);
        ___qtablewidgetitem42->setText(QApplication::translate("showtasknumdlg", "108", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(9, 1);
        ___qtablewidgetitem43->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(9, 2);
        ___qtablewidgetitem44->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(10, 0);
        ___qtablewidgetitem45->setText(QApplication::translate("showtasknumdlg", "109", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(10, 1);
        ___qtablewidgetitem46->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(10, 2);
        ___qtablewidgetitem47->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(11, 0);
        ___qtablewidgetitem48->setText(QApplication::translate("showtasknumdlg", "110", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(11, 1);
        ___qtablewidgetitem49->setText(QApplication::translate("showtasknumdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(11, 2);
        ___qtablewidgetitem50->setText(QApplication::translate("showtasknumdlg", "\346\234\252\345\256\232\344\271\211", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        labelshow->setText(QString());
        label_2->setText(QApplication::translate("showtasknumdlg", "\346\277\200\345\205\211\347\272\277:", nullptr));
        label_3->setText(QApplication::translate("showtasknumdlg", "\346\277\200\345\205\211\347\272\277\345\273\266\351\225\277\347\272\277:", nullptr));
        label_4->setText(QApplication::translate("showtasknumdlg", "\346\243\200\346\265\213\347\273\223\346\236\234:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showtasknumdlg: public Ui_showtasknumdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTASKNUMDLG_H

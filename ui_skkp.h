/********************************************************************************
** Form generated from reading UI file 'skkp.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKKP_H
#define UI_SKKP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_skkp
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_12;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_16;
    QListWidget *listWidget_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_13;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_14;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_15;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *skkp)
    {
        if (skkp->objectName().isEmpty())
            skkp->setObjectName(QStringLiteral("skkp"));
        skkp->resize(1467, 610);
        centralWidget = new QWidget(skkp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setEnabled(true);

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setEnabled(true);
        doubleSpinBox_12->setDecimals(10);
        doubleSpinBox_12->setMaximum(1e+09);
        doubleSpinBox_12->setSingleStep(0.5);
        doubleSpinBox_12->setValue(0);

        gridLayout_3->addWidget(doubleSpinBox_12, 0, 1, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setEnabled(true);

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        doubleSpinBox_16 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_16->setObjectName(QStringLiteral("doubleSpinBox_16"));
        doubleSpinBox_16->setEnabled(true);
        doubleSpinBox_16->setDecimals(10);
        doubleSpinBox_16->setMaximum(1e+09);
        doubleSpinBox_16->setSingleStep(0.5);
        doubleSpinBox_16->setValue(1000);

        gridLayout_3->addWidget(doubleSpinBox_16, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 1);

        listWidget_4 = new QListWidget(centralWidget);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));

        gridLayout_4->addWidget(listWidget_4, 5, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setEnabled(true);
        doubleSpinBox_7->setDecimals(10);
        doubleSpinBox_7->setMinimum(-100000);
        doubleSpinBox_7->setMaximum(100000);
        doubleSpinBox_7->setSingleStep(0.5);
        doubleSpinBox_7->setValue(0.5235);

        gridLayout->addWidget(doubleSpinBox_7, 2, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setEnabled(true);
        doubleSpinBox_6->setDecimals(10);
        doubleSpinBox_6->setMinimum(-100000);
        doubleSpinBox_6->setMaximum(100000);
        doubleSpinBox_6->setSingleStep(0.5);
        doubleSpinBox_6->setValue(1.3961);

        gridLayout->addWidget(doubleSpinBox_6, 1, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setEnabled(true);
        doubleSpinBox_8->setDecimals(10);
        doubleSpinBox_8->setMinimum(-100000);
        doubleSpinBox_8->setMaximum(100000);
        doubleSpinBox_8->setSingleStep(0.5);
        doubleSpinBox_8->setValue(0.6354);

        gridLayout->addWidget(doubleSpinBox_8, 3, 2, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setEnabled(true);
        doubleSpinBox_4->setDecimals(10);
        doubleSpinBox_4->setMinimum(-100000);
        doubleSpinBox_4->setMaximum(100000);
        doubleSpinBox_4->setSingleStep(0.5);
        doubleSpinBox_4->setValue(0.826);

        gridLayout->addWidget(doubleSpinBox_4, 3, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(true);
        doubleSpinBox_2->setDecimals(10);
        doubleSpinBox_2->setMinimum(-100000);
        doubleSpinBox_2->setMaximum(100000);
        doubleSpinBox_2->setSingleStep(0.5);
        doubleSpinBox_2->setValue(1.6769);

        gridLayout->addWidget(doubleSpinBox_2, 1, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(true);
        doubleSpinBox_3->setDecimals(10);
        doubleSpinBox_3->setMinimum(-100000);
        doubleSpinBox_3->setMaximum(100000);
        doubleSpinBox_3->setSingleStep(0.5);
        doubleSpinBox_3->setValue(0.9348);

        gridLayout->addWidget(doubleSpinBox_3, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 2);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_4->addWidget(listWidget, 0, 2, 3, 1);

        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        gridLayout_4->addWidget(listWidget_2, 0, 3, 3, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 5, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(true);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setEnabled(true);

        gridLayout_2->addWidget(label_13, 0, 1, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setEnabled(true);

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(true);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setEnabled(true);
        doubleSpinBox_9->setDecimals(10);
        doubleSpinBox_9->setMaximum(1e+09);
        doubleSpinBox_9->setSingleStep(0.5);
        doubleSpinBox_9->setValue(8465.67);

        gridLayout_2->addWidget(doubleSpinBox_9, 1, 1, 1, 1);

        doubleSpinBox_13 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setEnabled(true);
        doubleSpinBox_13->setDecimals(10);
        doubleSpinBox_13->setMaximum(1e+09);
        doubleSpinBox_13->setSingleStep(0.5);
        doubleSpinBox_13->setValue(8928.38);

        gridLayout_2->addWidget(doubleSpinBox_13, 1, 2, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setEnabled(true);
        doubleSpinBox_10->setDecimals(10);
        doubleSpinBox_10->setMinimum(-100000);
        doubleSpinBox_10->setMaximum(100000);
        doubleSpinBox_10->setSingleStep(0.5);
        doubleSpinBox_10->setValue(3.9893);

        gridLayout_2->addWidget(doubleSpinBox_10, 2, 1, 1, 1);

        doubleSpinBox_14 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        doubleSpinBox_14->setEnabled(true);
        doubleSpinBox_14->setDecimals(10);
        doubleSpinBox_14->setMinimum(-100000);
        doubleSpinBox_14->setMaximum(100000);
        doubleSpinBox_14->setSingleStep(0.5);
        doubleSpinBox_14->setValue(7.6387);

        gridLayout_2->addWidget(doubleSpinBox_14, 2, 2, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setEnabled(true);

        gridLayout_2->addWidget(label_11, 3, 0, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setEnabled(true);
        doubleSpinBox_11->setDecimals(10);
        doubleSpinBox_11->setMinimum(-100000);
        doubleSpinBox_11->setMaximum(100000);
        doubleSpinBox_11->setSingleStep(0.5);
        doubleSpinBox_11->setValue(0.6217);

        gridLayout_2->addWidget(doubleSpinBox_11, 3, 1, 1, 1);

        doubleSpinBox_15 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));
        doubleSpinBox_15->setEnabled(true);
        doubleSpinBox_15->setDecimals(10);
        doubleSpinBox_15->setMinimum(-100000);
        doubleSpinBox_15->setMaximum(100000);
        doubleSpinBox_15->setSingleStep(0.5);
        doubleSpinBox_15->setValue(0.0007);

        gridLayout_2->addWidget(doubleSpinBox_15, 3, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 2);

        skkp->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(skkp);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1467, 26));
        skkp->setMenuBar(menuBar);
        mainToolBar = new QToolBar(skkp);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        skkp->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(skkp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        skkp->setStatusBar(statusBar);

        retranslateUi(skkp);

        QMetaObject::connectSlotsByName(skkp);
    } // setupUi

    void retranslateUi(QMainWindow *skkp)
    {
        skkp->setWindowTitle(QApplication::translate("skkp", "skkp", 0));
        label_12->setText(QApplication::translate("skkp", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217:", 0));
        label_15->setText(QApplication::translate("skkp", "\320\232\320\276\320\275\320\265\321\207\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217:", 0));
        label->setText(QApplication::translate("skkp", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\200\320\261\320\270\321\202\321\213:", 0));
        label_4->setText(QApplication::translate("skkp", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260 \320\262\320\276\321\201\321\205\320\276\320\264\321\217\321\211\320\265\320\263\320\276 \321\203\320\267\320\273\320\260:", 0));
        label_7->setText(QApplication::translate("skkp", "\320\241\320\277\321\203\321\202\320\275\320\270\320\272", 0));
        label_3->setText(QApplication::translate("skkp", "\320\235\320\260\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\270 \320\276\321\200\320\261\320\270\321\202\321\213:", 0));
        label_6->setText(QApplication::translate("skkp", "\320\246\320\265\320\273\321\214", 0));
        label_5->setText(QApplication::translate("skkp", "\320\220\321\200\320\263\321\203\320\274\320\265\320\275\321\202 \321\210\320\270\321\200\320\276\321\202\321\213:", 0));
        pushButton->setText(QApplication::translate("skkp", "\320\241\321\202\320\260\321\200\321\202", 0));
        pushButton_2->setText(QApplication::translate("skkp", "\320\241\321\202\320\276\320\277", 0));
        label_8->setText(QApplication::translate("skkp", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", 0));
        label_13->setText(QApplication::translate("skkp", "\320\246\320\265\320\273\321\214", 0));
        label_14->setText(QApplication::translate("skkp", "\320\241\320\277\321\203\321\202\320\275\320\270\320\272", 0));
        label_9->setText(QApplication::translate("skkp", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\200\320\260\320\264\320\270\321\203\321\201 \320\262\320\265\320\272\321\202\320\276\321\200:", 0));
        label_10->setText(QApplication::translate("skkp", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", 0));
        label_11->setText(QApplication::translate("skkp", "\320\243\320\263\320\276\320\273 \320\275\320\260\320\272\320\273\320\276\320\275\320\260 \320\262\320\265\320\272\321\202\320\276\321\200\320\260 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\272 \320\274\320\265\321\201\321\202\320\275\320\276\320\274\321\203 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\321\203:", 0));
    } // retranslateUi

};

namespace Ui {
    class skkp: public Ui_skkp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKKP_H

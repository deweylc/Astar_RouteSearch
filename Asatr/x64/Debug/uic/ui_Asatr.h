/********************************************************************************
** Form generated from reading UI file 'Asatr.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASATR_H
#define UI_ASATR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AsatrClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *InputStart;
    QLineEdit *InputEnd;
    QLineEdit *Search;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AsatrClass)
    {
        if (AsatrClass->objectName().isEmpty())
            AsatrClass->setObjectName(QStringLiteral("AsatrClass"));
        AsatrClass->resize(1123, 906);
        centralWidget = new QWidget(AsatrClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 48, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 10, 48, 16));
        InputStart = new QLineEdit(centralWidget);
        InputStart->setObjectName(QStringLiteral("InputStart"));
        InputStart->setGeometry(QRect(140, 10, 133, 20));
        InputEnd = new QLineEdit(centralWidget);
        InputEnd->setObjectName(QStringLiteral("InputEnd"));
        InputEnd->setGeometry(QRect(340, 10, 133, 20));
        Search = new QLineEdit(centralWidget);
        Search->setObjectName(QStringLiteral("Search"));
        Search->setGeometry(QRect(10, 790, 1041, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Search->sizePolicy().hasHeightForWidth());
        Search->setSizePolicy(sizePolicy);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 760, 48, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 40, 75, 23));
        AsatrClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AsatrClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 23));
        AsatrClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AsatrClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AsatrClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AsatrClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AsatrClass->setStatusBar(statusBar);

        retranslateUi(AsatrClass);
        QObject::connect(pushButton, SIGNAL(clicked()), AsatrClass, SLOT(GetPath()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AsatrClass, SLOT(ClearSearch()));

        QMetaObject::connectSlotsByName(AsatrClass);
    } // setupUi

    void retranslateUi(QMainWindow *AsatrClass)
    {
        AsatrClass->setWindowTitle(QApplication::translate("AsatrClass", "Asatr", Q_NULLPTR));
        label->setText(QApplication::translate("AsatrClass", "\350\265\267\345\247\213\350\212\202\347\202\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("AsatrClass", "\347\233\256\346\240\207\347\273\223\347\202\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("AsatrClass", "\346\220\234\347\264\242\347\273\223\346\236\234", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AsatrClass", "\346\220\234\347\264\242\350\277\233\350\267\257", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AsatrClass", "\351\207\215\347\275\256\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AsatrClass: public Ui_AsatrClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASATR_H

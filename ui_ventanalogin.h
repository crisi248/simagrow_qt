/********************************************************************************
** Form generated from reading UI file 'ventanalogin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANALOGIN_H
#define UI_VENTANALOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaLogin
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditCorreo;
    QLineEdit *lineEditPass;
    QPushButton *btLogin;
    QLabel *labelErrorPass;
    QLabel *labelErrorUsuario;
    QLabel *labelErrorInicio;

    void setupUi(QMainWindow *VentanaLogin)
    {
        if (VentanaLogin->objectName().isEmpty())
            VentanaLogin->setObjectName(QString::fromUtf8("VentanaLogin"));
        VentanaLogin->resize(320, 205);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VentanaLogin->sizePolicy().hasHeightForWidth());
        VentanaLogin->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(VentanaLogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 201, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 201, 18));
        lineEditCorreo = new QLineEdit(centralwidget);
        lineEditCorreo->setObjectName(QString::fromUtf8("lineEditCorreo"));
        lineEditCorreo->setGeometry(QRect(20, 40, 281, 32));
        lineEditPass = new QLineEdit(centralwidget);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        lineEditPass->setGeometry(QRect(20, 100, 281, 32));
        lineEditPass->setEchoMode(QLineEdit::Password);
        btLogin = new QPushButton(centralwidget);
        btLogin->setObjectName(QString::fromUtf8("btLogin"));
        btLogin->setGeometry(QRect(20, 150, 101, 34));
        labelErrorPass = new QLabel(centralwidget);
        labelErrorPass->setObjectName(QString::fromUtf8("labelErrorPass"));
        labelErrorPass->setGeometry(QRect(100, 80, 151, 18));
        labelErrorPass->setStyleSheet(QString::fromUtf8("color: red;"));
        labelErrorUsuario = new QLabel(centralwidget);
        labelErrorUsuario->setObjectName(QString::fromUtf8("labelErrorUsuario"));
        labelErrorUsuario->setGeometry(QRect(150, 20, 151, 18));
        labelErrorUsuario->setStyleSheet(QString::fromUtf8("color: red;"));
        labelErrorInicio = new QLabel(centralwidget);
        labelErrorInicio->setObjectName(QString::fromUtf8("labelErrorInicio"));
        labelErrorInicio->setGeometry(QRect(20, 130, 281, 18));
        labelErrorInicio->setStyleSheet(QString::fromUtf8("color: red;"));
        VentanaLogin->setCentralWidget(centralwidget);

        retranslateUi(VentanaLogin);

        QMetaObject::connectSlotsByName(VentanaLogin);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaLogin)
    {
        VentanaLogin->setWindowTitle(QCoreApplication::translate("VentanaLogin", "Inicio de Sesi\303\263n", nullptr));
        label->setText(QCoreApplication::translate("VentanaLogin", "Correo Corporativo", nullptr));
        label_2->setText(QCoreApplication::translate("VentanaLogin", "Contrase\303\261a", nullptr));
        btLogin->setText(QCoreApplication::translate("VentanaLogin", "Iniciar Sesi\303\263n", nullptr));
        labelErrorPass->setText(QString());
        labelErrorUsuario->setText(QString());
        labelErrorInicio->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VentanaLogin: public Ui_VentanaLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANALOGIN_H

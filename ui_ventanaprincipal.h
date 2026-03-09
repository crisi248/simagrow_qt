/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralwidget;
    QListWidget *listaIncidencias;
    QLabel *label;
    QTextBrowser *textoDescripcion;
    QLabel *labelIdIncidencia;
    QLabel *label_2;
    QLabel *labelUbicacion;
    QLabel *label_3;
    QLabel *labelUsuario;
    QLabel *label_4;
    QLabel *labelIdUsuario;
    QCheckBox *checkBoxResuelto;
    QLabel *labelTitulo;
    QPushButton *btGuardar;
    QLabel *labelAdvertencia;
    QLabel *label_5;
    QLabel *labelFecha;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(818, 393);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VentanaPrincipal->sizePolicy().hasHeightForWidth());
        VentanaPrincipal->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listaIncidencias = new QListWidget(centralwidget);
        listaIncidencias->setObjectName(QString::fromUtf8("listaIncidencias"));
        listaIncidencias->setGeometry(QRect(15, 11, 451, 311));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 40, 91, 18));
        label->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        textoDescripcion = new QTextBrowser(centralwidget);
        textoDescripcion->setObjectName(QString::fromUtf8("textoDescripcion"));
        textoDescripcion->setGeometry(QRect(480, 80, 321, 111));
        labelIdIncidencia = new QLabel(centralwidget);
        labelIdIncidencia->setObjectName(QString::fromUtf8("labelIdIncidencia"));
        labelIdIncidencia->setGeometry(QRect(570, 40, 231, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 60, 71, 18));
        label_2->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        labelUbicacion = new QLabel(centralwidget);
        labelUbicacion->setObjectName(QString::fromUtf8("labelUbicacion"));
        labelUbicacion->setGeometry(QRect(550, 60, 241, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 220, 61, 18));
        label_3->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        labelUsuario = new QLabel(centralwidget);
        labelUsuario->setObjectName(QString::fromUtf8("labelUsuario"));
        labelUsuario->setGeometry(QRect(540, 220, 261, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 240, 71, 18));
        label_4->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        labelIdUsuario = new QLabel(centralwidget);
        labelIdUsuario->setObjectName(QString::fromUtf8("labelIdUsuario"));
        labelIdUsuario->setGeometry(QRect(555, 240, 231, 20));
        checkBoxResuelto = new QCheckBox(centralwidget);
        checkBoxResuelto->setObjectName(QString::fromUtf8("checkBoxResuelto"));
        checkBoxResuelto->setEnabled(false);
        checkBoxResuelto->setGeometry(QRect(480, 270, 151, 22));
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName(QString::fromUtf8("labelTitulo"));
        labelTitulo->setGeometry(QRect(480, 0, 321, 41));
        labelTitulo->setStyleSheet(QString::fromUtf8("font-weight: bold; font-size: 16pt;"));
        btGuardar = new QPushButton(centralwidget);
        btGuardar->setObjectName(QString::fromUtf8("btGuardar"));
        btGuardar->setGeometry(QRect(680, 290, 121, 34));
        labelAdvertencia = new QLabel(centralwidget);
        labelAdvertencia->setObjectName(QString::fromUtf8("labelAdvertencia"));
        labelAdvertencia->setGeometry(QRect(480, 290, 181, 18));
        labelAdvertencia->setStyleSheet(QString::fromUtf8("font-size: 8pt; color: red; "));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 200, 61, 18));
        label_5->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        labelFecha = new QLabel(centralwidget);
        labelFecha->setObjectName(QString::fromUtf8("labelFecha"));
        labelFecha->setGeometry(QRect(525, 200, 261, 20));
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 818, 30));
        VentanaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaPrincipal->setStatusBar(statusbar);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QCoreApplication::translate("VentanaPrincipal", "Incidencias", nullptr));
        label->setText(QCoreApplication::translate("VentanaPrincipal", "Id Incidencia:", nullptr));
        labelIdIncidencia->setText(QString());
        label_2->setText(QCoreApplication::translate("VentanaPrincipal", "Ubicaci\303\263n:", nullptr));
        labelUbicacion->setText(QString());
        label_3->setText(QCoreApplication::translate("VentanaPrincipal", "Usuario:", nullptr));
        labelUsuario->setText(QString());
        label_4->setText(QCoreApplication::translate("VentanaPrincipal", "Id Usuario:", nullptr));
        labelIdUsuario->setText(QString());
        checkBoxResuelto->setText(QCoreApplication::translate("VentanaPrincipal", "Incidencia Resuelta", nullptr));
        labelTitulo->setText(QCoreApplication::translate("VentanaPrincipal", "Detalles de la Incidencia", nullptr));
        btGuardar->setText(QCoreApplication::translate("VentanaPrincipal", "Guardar Cambios", nullptr));
        labelAdvertencia->setText(QString());
        label_5->setText(QCoreApplication::translate("VentanaPrincipal", "Fecha:", nullptr));
        labelFecha->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H

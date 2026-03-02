#ifndef _VENTANAPRINCIPAL_H
#define _VENTANAPRINCIPAL_H

#include "ui_ventanaprincipal.h"
#include "usuario.h"
#include "incidencia.h"

#include<QMainWindow>
#include<QPaintEvent>
#include<QVector>
#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class VentanaPrincipal : public QMainWindow, public Ui::VentanaPrincipal {
    Q_OBJECT

public:
    VentanaPrincipal(Usuario*, QWidget * parent = NULL);

    Usuario * usuario;
    QVector<Incidencia*> incidencias;

    QLabel* etiquetaUsuario;

public slots:

    void crearBarraEstado();

};

#endif

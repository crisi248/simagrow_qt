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
    Incidencia * incidenciaActual;

    QLabel* etiquetaUsuario;
    enum Filtro { TODOS, RESUELTOS, NO_RESUELTOS };

    void crearBarraEstado();
    void inicializarIncidencias();
    void reiniciarLista(Filtro);
    void crearMenu();

public slots:

    void slotResolverIncidencia(int);
    void slotGuardarIncidencia();
    void slotCargarDatosIncidencia(QListWidgetItem*);
    void slotRecargarIncidencias();

    void slotFiltrarTodos();
    void slotFiltrarResueltos();
    void slotFiltrarNoResueltos();

};

#endif

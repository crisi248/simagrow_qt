#include "ventanaprincipal.h"


#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QImage>
#include <math.h>

VentanaPrincipal::VentanaPrincipal(Usuario* usuarioPasado,QWidget * parent) : QMainWindow(parent) {
        setupUi(this);

        this->setFixedSize(800, 393);
        usuario = usuarioPasado;
        inicializarIncidencias();
        crearBarraEstado();
        crearMenu();

        incidenciaActual = NULL;

        connect(btGuardar,SIGNAL(pressed()),
                this,SLOT(slotGuardarIncidencia()));

        connect(listaIncidencias, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(slotCargarDatosIncidencia(QListWidgetItem*)));

}

void VentanaPrincipal::slotGuardarIncidencia() {
        if(incidenciaActual == NULL)  {
                return;
        }

         incidenciaActual->resuelta = checkBoxResuelto->isChecked();
         labelAdvertencia->clear();
         reiniciarLista(TODOS);
}

void VentanaPrincipal::slotResolverIncidencia(int estado) {
        checkBoxResuelto->setChecked(estado);
        labelAdvertencia->setText("Cambios sin guardar");
}

void VentanaPrincipal::slotCargarDatosIncidencia(QListWidgetItem* item) {

        incidenciaActual = incidencias.at(listaIncidencias->row(item));

        labelIdIncidencia->setText(QString::number(incidenciaActual->idIncidencia));
        labelUbicacion->setText(incidenciaActual->ubicacion);
        textoDescripcion->setText(incidenciaActual->descripcion);
        labelUsuario->setText(incidenciaActual->nombreUsuarioReporte);
        labelIdUsuario->setText(QString::number(incidenciaActual->idUsuarioReporte));

        labelAdvertencia->clear();
        disconnect(checkBoxResuelto, SIGNAL(stateChanged(int)), this, SLOT(slotResolverIncidencia(int)));
        checkBoxResuelto->setChecked(incidenciaActual->resuelta);
        connect(checkBoxResuelto, SIGNAL(stateChanged(int)), this, SLOT(slotResolverIncidencia(int)));
}
void VentanaPrincipal::inicializarIncidencias() {
        incidencias.clear();
        for (int i = 0; i < 10 ; i++ ) {
                Incidencia * incidencia = new Incidencia(i, QString("Descripcion de la incidencia"), QString("Aula de informática"), false, (i*10 + 6), QString("Usuario" ) + QString::number(i));
                incidencias.append(incidencia);
        }
        reiniciarLista(TODOS);
}

void VentanaPrincipal::reiniciarLista(Filtro filtro) {
        listaIncidencias->clear();
        for (int i = 0; i < incidencias.size(); i++) {
                Incidencia* inc = incidencias.at(i);

                if (filtro == RESUELTOS && !inc->resuelta) continue;
                if (filtro == NO_RESUELTOS && inc->resuelta) continue;

                QString cadena = QString("Id: %1\t%2\t%3")
                .arg(inc->idIncidencia)
                .arg(inc->ubicacion)
                .arg(inc->resuelta ? "resuelta" : "sin resolver");

                QListWidgetItem *item = new QListWidgetItem(cadena);
                item->setIcon(QApplication::style()->standardIcon(
                        inc->resuelta ? QStyle::SP_DialogApplyButton : QStyle::SP_MessageBoxCritical));
                listaIncidencias->addItem(item);
        }
}

void VentanaPrincipal::crearMenu() {
        QMenu *menuFiltrar = menuBar()->addMenu("Filtrar");
        menuFiltrar->addAction("Todos", this, SLOT(slotFiltrarTodos()));
        menuFiltrar->addAction("Resueltos", this, SLOT(slotFiltrarResueltos()));
        menuFiltrar->addAction("No resueltos", this, SLOT(slotFiltrarNoResueltos()));
}

void VentanaPrincipal::slotFiltrarTodos()        { reiniciarLista(TODOS); }
void VentanaPrincipal::slotFiltrarResueltos()    { reiniciarLista(RESUELTOS); }
void VentanaPrincipal::slotFiltrarNoResueltos()  { reiniciarLista(NO_RESUELTOS); }

void VentanaPrincipal::crearBarraEstado() {
        QStatusBar *barra = statusBar();

        QPushButton *btRecargar = new QPushButton();
        btRecargar->setIcon(QApplication::style()->standardIcon(QStyle::SP_BrowserReload));
        barra->addWidget(btRecargar);
        connect(btRecargar, SIGNAL(clicked()), this, SLOT(slotRecargarIncidencias()));

        etiquetaUsuario = new QLabel("Usuario: " + usuario->nombre + " " + usuario->apellidos);
        barra->addWidget(etiquetaUsuario);
}

void VentanaPrincipal::slotRecargarIncidencias() {
        inicializarIncidencias();
}


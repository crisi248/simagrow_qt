#include "ventanaprincipal.h"
#include "incidenciasapiclient.h"
#include "jsonincidencias.h"

#include <QPainter>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QImage>
#include <math.h>

VentanaPrincipal::VentanaPrincipal(Usuario* usuarioPasado,QWidget * parent) : QMainWindow(parent) {
        setupUi(this);

        this->setFixedSize(818, 393);
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
    if(incidenciaActual == NULL || !cambioSinGuardar) {
        return;
    }

    // Actualizar valor local
    incidenciaActual->resuelta = checkBoxResuelto->isChecked();
        /*
    // Enviar cambio a la API
    IncidenciasApiClient *client = new IncidenciasApiClient(this);
    client->updateResuelta(incidenciaActual->idIncidencia);
        */
    cambioSinGuardar = false;
    labelAdvertencia->clear();
    reiniciarLista(TODOS);
}

void VentanaPrincipal::slotResolverIncidencia(int estado) {

    cambioSinGuardar = (estado != incidenciaActual->resuelta);

    if (cambioSinGuardar) {
        labelAdvertencia->setText("Cambios sin guardar");
    } else {
        labelAdvertencia->clear();
    }
}

void VentanaPrincipal::slotCargarDatosIncidencia(QListWidgetItem* item) {

        cambioSinGuardar = false;
        checkBoxResuelto->setEnabled(true);

        incidenciaActual = incidencias.at(listaIncidencias->row(item));

        labelTitulo->setText(incidenciaActual->titulo);
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
    IncidenciasApiClient *client = new IncidenciasApiClient(this);
    connect(client, SIGNAL(signalIncidenciasRecibidas(QByteArray)),
            this, SLOT(slotIncidenciasRecibidas(QByteArray)));
    connect(client, SIGNAL(signalErrorPeticion()),
            this, SLOT(slotErrorIncidencias()));
}

void VentanaPrincipal::slotIncidenciasRecibidas(QByteArray datos) {
    JsonIncidencias parser(datos);
    incidencias = parser.getIncidencias();
    reiniciarLista(TODOS);
}

void VentanaPrincipal::slotErrorIncidencias() {
    qDebug() << "Error al cargar incidencias";
}

void VentanaPrincipal::reiniciarLista(Filtro filtro) {
    listaIncidencias->clear();

    for (int i = 0; i < incidencias.size(); i++) {
        Incidencia* inc = incidencias.at(i);

        // Filtrado según el estado de la incidencia
        if (filtro == RESUELTOS && !inc->resuelta) continue;
        if (filtro == NO_RESUELTOS && inc->resuelta) continue;

        // Contenedor y layout del item
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->setContentsMargins(4, 2, 4, 2);
        layout->setSpacing(0);

        // Icono con tinte verde (resuelta) o rojo (no resuelta)
        QLabel *icono = new QLabel();
        QIcon icon = QApplication::style()->standardIcon(
            inc->resuelta ? QStyle::SP_DialogApplyButton : QStyle::SP_MessageBoxCritical);
        QPixmap pixmap = icon.pixmap(16, 16);
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        painter.fillRect(pixmap.rect(), inc->resuelta ? QColor(0, 180, 0) : QColor(220, 0, 0));
        painter.end();
        icono->setPixmap(pixmap);
        icono->setFixedWidth(24);

        // Columna ID
        QLabel *labelId = new QLabel(QString("Id: %1").arg(inc->idIncidencia));
        labelId->setFixedWidth(50);
        labelId->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        // Columna título
        QLabel *labelTit = new QLabel(inc->titulo);
        labelTit->setFixedWidth(200);
        labelTit->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        // Columna ubicación
        QLabel *labelUbic = new QLabel(inc->ubicacion);
        labelUbic->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        labelUbic->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        // Añadir columnas al layout
        layout->addWidget(icono);
        layout->addWidget(labelId);
        layout->addWidget(labelTit);
        layout->addWidget(labelUbic);
        widget->setLayout(layout);

        // Añadir el widget como item de la lista
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());
        listaIncidencias->addItem(item);
        listaIncidencias->setItemWidget(item, widget);
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


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
        crearBarraEstado();
}

void VentanaPrincipal::crearBarraEstado() {
	QStatusBar *barra = statusBar();

	etiquetaUsuario = new QLabel("Usuario: " + usuario->nombre + " " + usuario->apellidos);
	barra->addWidget(etiquetaUsuario);
}


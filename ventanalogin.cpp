
#include "ventanalogin.h"
#include <QDebug>

VentanaLogin::VentanaLogin(QWidget *parent): QMainWindow(parent){
		setupUi(this);

	this->setFixedSize(320, 205);

	connect(btLogin,SIGNAL(pressed()),
		this,SLOT(slotLogin()));
	
}


void VentanaLogin::slotLogin(){

	bool error = false;

	QString correo = lineEditCorreo->text();
	QString pass = lineEditPass->text();

	if(correo.isEmpty()) {
		labelErrorUsuario->setText("Campo obligatorio");
		error = true;
	}
	if(pass.isEmpty()) {
		labelErrorPass->setText("Campo obligatorio");
		error = true;
	}

	// FALTA VERIFICACION DE USUARIO
	if(correo.isEmpty() || pass.isEmpty()) {
		labelErrorInicio->setText("El usuario o contraseña incorrectos");
		error = true;
	}

	if (error) {
		return;
	}

	usuario = new Usuario("Nombre", "Apellido1 Apellido2", "correoelectronico@prueba.com");

	qDebug() << "Bienvenido " << usuario->nombre;

	VentanaPrincipal * ventana = new VentanaPrincipal(usuario);
	ventana->show();

	 this->close();
	 this->deleteLater();
}


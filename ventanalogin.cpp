
#include "ventanalogin.h"
#include "userapiclient.h"
#include "jsonuser.h"
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

	labelErrorUsuario->clear();
	labelErrorPass->clear();
	labelErrorInicio->clear();

	if(correo.isEmpty()) {
		labelErrorUsuario->setText("Campo obligatorio");
		error = true;
	}
	if(pass.isEmpty()) {
		labelErrorPass->setText("Campo obligatorio");
		error = true;
	}

	if (error) {
		return;
	}

	UserApiClient * userApiClient = new UserApiClient(correo, pass);

	connect(userApiClient,SIGNAL(signalUsuarioRecibido(QByteArray)),
				this,SLOT(slotUsuarioRecibido(QByteArray)));

	connect(userApiClient,SIGNAL(signalErrorPeticion(QString)),
				this,SLOT(slotErrorPeticion(QString)));

	// FALTA VERIFICACION DE USUARIO

	/*
	usuario = new Usuario("Nombre", "Apellido1 Apellido2", "correoelectronico@prueba.com", false);
	VentanaPrincipal * ventana = new VentanaPrincipal(usuario);
	ventana->show();

	 this->close();
	 this->deleteLater();
	 */

}

void VentanaLogin::slotUsuarioRecibido(QByteArray datosRecibidos){

	JsonUser parser(datosRecibidos);
	usuario = new Usuario(*parser.getUser());

	if (usuario->isAdmin == false) {
		labelErrorInicio->setText("El usuario " + usuario->nombre + " no es administrador");
		return;
	}

	VentanaPrincipal * ventana = new VentanaPrincipal(usuario);
	ventana->show();

	this->close();
	this->deleteLater();

}

void VentanaLogin::slotErrorPeticion(QString respuesta){
	qDebug() << respuesta;
	if (respuesta == "203") {
		labelErrorInicio->setText("El usuario o contraseña incorrectos");
	}
	if (respuesta == "201") {
		labelErrorInicio->setText("El usuario no es administrador");
	}

}



#ifndef VENTANALOGIN_H
#define VENTANALOGIN_H
#include "ui_ventanalogin.h"
#include "ventanaprincipal.h"
#include "usuario.h"

#include <QVector>
#include <QMainWindow>
#include <QHBoxLayout>

class VentanaLogin : public QMainWindow, public Ui::VentanaLogin {
Q_OBJECT

public:
	VentanaLogin(QWidget *parent = NULL);

	Usuario * usuario;

public slots:
	void slotLogin();
	void slotUsuarioRecibido(QByteArray);
	void slotErrorPeticion(QString);

};

#endif 

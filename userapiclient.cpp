#include "userapiclient.h"
#include <QDebug>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QTimer>

UserApiClient::UserApiClient(QString correoBuscado, QString passBuscada, QObject * parent): QObject(parent){

	manager = new QNetworkAccessManager(this);

	connect(manager,SIGNAL(finished(QNetworkReply *)),
			this,SLOT(slotRespuestaFinalizada(QNetworkReply *)));

	// JSON TEMPORAL
	QByteArray jsonFalso = R"({
        "id": 7,
        "nombre": "Pepe",
        "apellidos": "García",
        "email": "pepe@alu.edu.gva.es",
        "admin": true
    })";
    QTimer::singleShot(0, this, [this, jsonFalso]() {
        emit signalUsuarioRecibido(jsonFalso);
    });

	//fetch(correoBuscado, passBuscada);
}

void UserApiClient::slotRespuestaFinalizada(QNetworkReply * respuesta){

	if (respuesta->error() != QNetworkReply::NoError) {
		qDebug() << "Error " << respuesta->error() ;
		emit signalErrorPeticion();
		return;
	}

	QByteArray datosCrudos = respuesta->readAll();
	QString textoRecibido = QString(datosCrudos);

	emit signalUsuarioRecibido(datosCrudos);

}


void UserApiClient::fetch(QString correoBuscado, QString passBuscada) {
    QNetworkRequest request;
    request.setRawHeader("Accept", "application/json");

    //CAMBIAR URL
    QUrl url("http://localhost:8080/api/users");
    QUrlQuery query;
    query.addQueryItem("email", correoBuscado);
    query.addQueryItem("contrasenya", passBuscada);
    url.setQuery(query);

    request.setUrl(url);
    manager->get(request);
}







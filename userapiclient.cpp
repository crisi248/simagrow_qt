#include "userapiclient.h"
#include <QDebug>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>

UserApiClient::UserApiClient(QString correoBuscado, QString passBuscada, QObject * parent): QObject(parent){

	manager = new QNetworkAccessManager(this);

	connect(manager,SIGNAL(finished(QNetworkReply *)),
			this,SLOT(slotRespuestaFinalizada(QNetworkReply *)));

	/* JSON TEMPORAL
	QByteArray jsonFalso = R"({
        "id": 7,
        "nombre": "Pepe",
        "apellidos": "García",
        "correo": "pepe@alu.edu.gva.es",
        "admin": true
    })";
    QTimer::singleShot(0, this, [this, jsonFalso]() {
        emit signalUsuarioRecibido(jsonFalso);
    });
*/

	fetch(correoBuscado, passBuscada);
}

void UserApiClient::slotRespuestaFinalizada(QNetworkReply * respuesta){

	if (respuesta->error() != QNetworkReply::NoError) {
		qDebug() << "Error " << respuesta->error() ;
		emit signalErrorPeticion(QString::number(respuesta->error()));
		return;
	}

	QByteArray datosCrudos = respuesta->readAll();
	QString textoRecibido = QString(datosCrudos);

	emit signalUsuarioRecibido(datosCrudos);

}


void UserApiClient::fetch(QString correoBuscado, QString passBuscada) {
    QNetworkRequest request;
    request.setRawHeader("Accept", "application/json");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QUrl url("http://68.221.171.14/simagrow/users/login");
    request.setUrl(url);

    // Construir el JSON body
    QJsonObject jsonBody;
    jsonBody["correo"] = correoBuscado;
    jsonBody["contrasena"] = passBuscada;

    QJsonDocument doc(jsonBody);
    QByteArray data = doc.toJson();

    manager->post(request, data);  // POST con body, no GET con query params
}







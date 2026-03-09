#include "incidenciasapiclient.h"
#include <QDebug>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>

IncidenciasApiClient::IncidenciasApiClient(QObject * parent): QObject(parent){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(slotRespuestaFinalizada(QNetworkReply *)));

    // MOCK TEMPORAL — quitar cuando la API funcione

    fetch();  // descomentar cuando la API funcione
}

void IncidenciasApiClient::slotRespuestaFinalizada(QNetworkReply * respuesta){
    if (respuesta->error() != QNetworkReply::NoError) {
        qDebug() << "Error " << respuesta->error();
        emit signalErrorPeticion();
        return;
    }
    QByteArray datosCrudos = respuesta->readAll();
    emit signalIncidenciasRecibidas(datosCrudos);
}

void IncidenciasApiClient::fetch() {
    QNetworkRequest request;
    request.setRawHeader("Accept", "application/json");
    // CAMBIAR URL
    QUrl url("http://68.221.171.14/simagrow/incidencies");
    request.setUrl(url);
    manager->get(request);
}

void IncidenciasApiClient::updateResuelta(int id) {
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QUrl url(QString("http://68.221.171.14/simagrow/incidencies/resuelta/%1").arg(id));
    request.setUrl(url);
    manager->put(request, QByteArray());
}

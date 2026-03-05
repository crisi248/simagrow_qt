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
    QByteArray jsonFalso = R"([
        {"id":1,"titulo":"Contenedor de papel lleno","descripcion":"El contenedor azul de la segunda planta está desbordado.","usuarioId":2,"usuarioNombre":"Lucas","usuarioApellidos":"Pérez","espacioNombre":"Aula 201","resuelta":false},
        {"id":2,"titulo":"Luces encendidas sin nadie","descripcion":"Al entrar al taller las luces estaban todas encendidas sin nadie dentro.","usuarioId":2,"usuarioNombre":"Lucas","usuarioApellidos":"Pérez","espacioNombre":"Taller de Automoción","resuelta":false},
        {"id":3,"titulo":"Ventana no cierra bien","descripcion":"La ventana izquierda del aula de dibujo no encaja y se escapa el calor.","usuarioId":2,"usuarioNombre":"Lucas","usuarioApellidos":"Pérez","espacioNombre":"Aula de Dibujo","resuelta":false},
        {"id":4,"titulo":"Proyector sin imagen","descripcion":"El proyector enciende pero no muestra imagen en la pantalla.","usuarioId":3,"usuarioNombre":"María","usuarioApellidos":"García","espacioNombre":"Aula 105","resuelta":false},
        {"id":5,"titulo":"Grifo con fuga","descripcion":"El grifo del lavabo de los vestuarios gotea continuamente.","usuarioId":3,"usuarioNombre":"María","usuarioApellidos":"García","espacioNombre":"Vestuarios","resuelta":true},
        {"id":6,"titulo":"Silla rota","descripcion":"Una silla de la primera fila tiene una pata suelta y es peligrosa.","usuarioId":4,"usuarioNombre":"Carlos","usuarioApellidos":"López","espacioNombre":"Aula 302","resuelta":false},
        {"id":7,"titulo":"Calefacción no funciona","descripcion":"La calefacción del aula lleva dos días sin calentarse.","usuarioId":4,"usuarioNombre":"Carlos","usuarioApellidos":"López","espacioNombre":"Aula 302","resuelta":false},
        {"id":8,"titulo":"Puerta bloqueada","descripcion":"La puerta del almacén no abre con la llave habitual.","usuarioId":5,"usuarioNombre":"Ana","usuarioApellidos":"Martínez","espacioNombre":"Almacén Principal","resuelta":true},
        {"id":9,"titulo":"Ordenador no arranca","descripcion":"El ordenador del puesto 7 no enciende al pulsar el botón de inicio.","usuarioId":5,"usuarioNombre":"Ana","usuarioApellidos":"Martínez","espacioNombre":"Aula de Informática","resuelta":false},
        {"id":10,"titulo":"Mancha en el techo","descripcion":"Hay una mancha de humedad grande en el techo cerca de la ventana.","usuarioId":6,"usuarioNombre":"Pedro","usuarioApellidos":"Sánchez","espacioNombre":"Biblioteca","resuelta":false},
        {"id":11,"titulo":"Enchufe quemado","descripcion":"El enchufe de la pared huele a quemado y tiene marcas negras.","usuarioId":6,"usuarioNombre":"Pedro","usuarioApellidos":"Sánchez","espacioNombre":"Sala de Profesores","resuelta":false},
        {"id":12,"titulo":"Persiana atascada","descripcion":"La persiana de la ventana derecha no sube ni baja.","usuarioId":7,"usuarioNombre":"Laura","usuarioApellidos":"Fernández","espacioNombre":"Aula 201","resuelta":true},
        {"id":13,"titulo":"Falta papel higiénico","descripcion":"Los dispensadores del baño de la planta baja llevan vacíos desde ayer.","usuarioId":7,"usuarioNombre":"Laura","usuarioApellidos":"Fernández","espacioNombre":"Baños Planta Baja","resuelta":false},
        {"id":14,"titulo":"Red WiFi caída","descripcion":"No hay conexión WiFi en toda la segunda planta desde esta mañana.","usuarioId":8,"usuarioNombre":"Jorge","usuarioApellidos":"Ruiz","espacioNombre":"Segunda Planta","resuelta":false},
        {"id":15,"titulo":"Mesa con cristal roto","descripcion":"La mesa del profesor tiene el cristal protector agrietado.","usuarioId":8,"usuarioNombre":"Jorge","usuarioApellidos":"Ruiz","espacioNombre":"Aula 105","resuelta":false},
        {"id":16,"titulo":"Alarma suena sola","descripcion":"La alarma del pasillo ha sonado dos veces sin motivo aparente.","usuarioId":9,"usuarioNombre":"Sara","usuarioApellidos":"Jiménez","espacioNombre":"Pasillo Central","resuelta":true},
        {"id":17,"titulo":"Dispensador de jabón roto","descripcion":"El dispensador de jabón del baño de chicas no funciona.","usuarioId":9,"usuarioNombre":"Sara","usuarioApellidos":"Jiménez","espacioNombre":"Baños Primera Planta","resuelta":false},
        {"id":18,"titulo":"Pizarra digital sin respuesta","descripcion":"La pizarra digital no responde al tacto aunque el sistema arranca.","usuarioId":10,"usuarioNombre":"Diego","usuarioApellidos":"Torres","espacioNombre":"Aula 403","resuelta":false},
        {"id":19,"titulo":"Cerradura forzada","descripcion":"La cerradura del aula parece haber sido forzada y no cierra bien.","usuarioId":10,"usuarioNombre":"Diego","usuarioApellidos":"Torres","espacioNombre":"Aula 403","resuelta":false},
        {"id":20,"titulo":"Baldosa suelta","descripcion":"Hay una baldosa suelta en la entrada principal que puede causar caídas.","usuarioId":11,"usuarioNombre":"Elena","usuarioApellidos":"Moreno","espacioNombre":"Entrada Principal","resuelta":true}
    ])";
    QTimer::singleShot(0, this, [this, jsonFalso]() {
        emit signalIncidenciasRecibidas(jsonFalso);
    });

    // fetch();  // descomentar cuando la API funcione
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
    QUrl url("http://localhost:8080/api/incidencias");
    request.setUrl(url);
    manager->get(request);
}

void IncidenciasApiClient::updateResuelta(int id) {
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QUrl url(QString("http://localhost:8080/api/incidencias/%1").arg(id));
    request.setUrl(url);
    manager->put(request, QByteArray());
}

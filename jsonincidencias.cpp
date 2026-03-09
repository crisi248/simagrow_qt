#include "jsonincidencias.h"
#include <QDebug>

JsonIncidencias::JsonIncidencias(QByteArray bytes) {
    QJsonDocument documento(QJsonDocument::fromJson(bytes));

    if (!documento.isArray()) {
        qDebug() << "Error: el JSON no es un array";
        return;
    }

    QJsonArray array = documento.array();
    for (int i = 0; i < array.size(); i++) {
        QJsonObject objeto = array[i].toObject();

        int id          = objeto["id"].toInt();
        QString titulo  = objeto["titulo"].toString();
        QString desc    = objeto["descripcion"].toString();
        int usuarioId   = objeto["usuarioId"].toInt();
        QString nombre  = objeto["usuarioNombre"].toString();
        QString apells  = objeto["usuarioApellidos"].toString();
        QString espacio = objeto["espacioNombre"].toString();
        bool resuelta   = objeto["resuelta"].toBool();
        QString fecha = objeto["fechaIncidencia"].toString();

        QString nombreCompleto = nombre + " " + apells;

        Incidencia* inc = new Incidencia(id, desc, titulo, espacio, resuelta, usuarioId, nombreCompleto, fecha);
        incidencias.prepend(inc);
    }
}

QVector<Incidencia*> JsonIncidencias::getIncidencias() { return incidencias; }

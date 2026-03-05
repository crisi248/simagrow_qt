#ifndef _JSON_INCIDENCIAS_
#define _JSON_INCIDENCIAS_
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QVector>
#include "incidencia.h"

class JsonIncidencias {
public:
    QVector<Incidencia*> incidencias;
    JsonIncidencias(QByteArray);
    QVector<Incidencia*> getIncidencias();
};
#endif

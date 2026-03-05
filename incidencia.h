#ifndef _INCIDENCIA_H_
#define _INCIDENCIA_H_
#include <QString>

class Incidencia {

public:
    Incidencia(int, QString, QString, QString, bool, int, QString);
    int idIncidencia, idUsuarioReporte;
    QString titulo, nombreUsuarioReporte, descripcion, ubicacion;
    bool resuelta;
};
#endif

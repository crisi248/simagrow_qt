#include"usuario.h"

Usuario::Usuario(QString nombrePasado, QString apellidosPasados, QString correoPasado, bool isAdminPasado) {

    nombre = nombrePasado;
    apellidos = apellidosPasados;
    correo = correoPasado;
    isAdmin = isAdminPasado;
}

#ifndef _USUARIO_H_
#define _USUARIO_H_
#include <QString>

class Usuario {

public:
    Usuario(QString,QString,QString, bool);
    QString nombre, apellidos, correo;
    bool isAdmin;

};
#endif

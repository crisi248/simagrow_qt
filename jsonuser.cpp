#include "jsonuser.h"
#include <QDebug>

JsonUser::JsonUser(QByteArray bytes) {
    QJsonDocument documento(QJsonDocument::fromJson(bytes));
    QJsonObject objeto = documento.object();
    QStringList claves = objeto.keys();

    QString nombre;
    QString apellidos;
    QString correo;
    bool isAdmin = false;

    if (claves.contains("nombre")) {
        QJsonValue valor = objeto["nombre"];
        if (valor.isString())
            nombre = valor.toString();
    }
    if (claves.contains("apellidos")) {
        QJsonValue valor = objeto["apellidos"];
        if (valor.isString())
            apellidos = valor.toString();
    }
    if (claves.contains("correo")) {
        QJsonValue valor = objeto["correo"];
        if (valor.isString())
            correo = valor.toString();
    }
    if (claves.contains("admin")) {
        QJsonValue valor = objeto["admin"];
        if (valor.isBool())
            isAdmin = valor.toBool();
    }

    qDebug() << "LOGIN SUCCESS: " << nombre << " " << apellidos << " - " << correo;

    miUser = new Usuario(nombre, apellidos, correo, isAdmin);
}

Usuario* JsonUser::getUser() { return miUser; }

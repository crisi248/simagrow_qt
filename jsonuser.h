#ifndef _JSON_USER_
#define _JSON_USER_
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include "usuario.h"

class JsonUser {

public :
    Usuario* miUser;
    JsonUser(QByteArray);

    Usuario* getUser();
};

#endif

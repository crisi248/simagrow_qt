#ifndef _USER_API_CLIENT_
#define _USER_API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class UserApiClient : public QObject {
Q_OBJECT

public:
	UserApiClient(QString, QString, QObject *parent = NULL);

	QNetworkAccessManager *manager;
	void fetch(QString, QString);


public slots:

	void slotRespuestaFinalizada(QNetworkReply * respuesta);

signals:
	void signalUsuarioRecibido(QByteArray);
	void signalErrorPeticion(QString);
};





#endif

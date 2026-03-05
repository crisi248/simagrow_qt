#ifndef _INCIDENCIAS_API_CLIENT_
#define _INCIDENCIAS_API_CLIENT_
#include <QNetworkAccessManager>
#include <QNetworkReply>
class IncidenciasApiClient : public QObject {
Q_OBJECT
public:
    IncidenciasApiClient(QObject *parent = NULL);
    QNetworkAccessManager *manager;
    void fetch();

    void updateResuelta(int);
public slots:
    void slotRespuestaFinalizada(QNetworkReply * respuesta);
signals:
    void signalIncidenciasRecibidas(QByteArray);
    void signalErrorPeticion();

};
#endif

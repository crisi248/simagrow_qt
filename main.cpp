#include <QApplication>
#include "ventanalogin.h"


 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     app.setWindowIcon(QIcon("simagrow.png"));
     VentanaLogin * ventana = new VentanaLogin();
     ventana->show();
  	  
     return app.exec();
 }

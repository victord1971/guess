
#include "appl.h"

//int argc_255;
//char argv_1[255];
Appl1* appl1;
//QTranslator trans;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator trans;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    qDebug() << "Element" << qrand();

    trans.load("appl_Uk.qm",".");

    //app.installTranslator(&trans);
    qApp->installTranslator(&trans);

    //Appl1 appl1;
    appl1=new Appl1;
    //qApp->installTranslator(&trans);
    appl1->setWindowTitle("4-4");
    appl1->resize(640,460);
    appl1->show();

    return app.exec();
}

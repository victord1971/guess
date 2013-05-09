

#ifndef start_h

#define start_h

//#include <QtQuick>
//#include <QApplication>
#include <QtWidgets>
#include <QtGui>
//#include <QX11Info>

#include <QWidget>
#include <QTableWidget>
#include <QTableView>

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QByteArray>
#include <QApplication>
#include <QTranslator>
#include <QTableWidgetItem>

extern class Appl1* appl1;
extern class Appl1* appl2;
//QTranslator veryTrans;

//extern int argc_255;
//extern char argv_1[255];
//extern QApplication app(/*argc, argv*/);
//extern QTranslator trans;

//class QLabel;
//class QPushButton;
//class QFrame;
//class QLineEdit;
//class QIntValidator;
//class QTranslator;
//extern class Appl1 appl1;

class Appl1 : public QWidget
{

Q_OBJECT

private:
    //QTranslator* trans;
    QFrame*      fr1;
    QFrame*      fr2;
    QFrame*      fr21;
    QFrame*      fr22;
    QFrame*      fr20;
    QLabel*      llll;
    QLabel*      l_compa_m;
    QLabel*      l_compare;
    QLabel*      l_comp1_5;
    QLabel*      l_compar2;
    QLabel*      l_try;
    QLabel*      l_error;
    QLabel*      l_more;
    QPushButton* bttnStart;
    QPushButton* bttnNext;
    QPushButton* bttnMore;
    QPushButton* bttnUk;
    QPushButton* bttnEn;
    QPushButton* bttnRu;
    QLineEdit*   le1;
    QLineEdit*   le2;
    QIntValidator*  validator;
    QIntValidator*  validato2;
    //QIntValidator*  validat_m;
    QTableWidget* table;    
    QStringList* listTable;
    QString* startString;
    QPixmap* pixUk;
    QPixmap* pixEn;
    QPixmap* pixRu;
    //QTranslator* veryTrans;
public:
    Appl1(QWidget* pwgt = 0);

public slots:
    void slotStartClicked();
    void slotNextClicked();
    void slotMoreClicked();
    void slotUkClicked();
    void slotEnClicked();
    void slotRuClicked();
    void selectionChanged21();
    void selectionChanged22();
    void textEdited21();
    void textEdited22();
    //void textChanged21();
    //void textChanged22();
};

#endif  //start_h

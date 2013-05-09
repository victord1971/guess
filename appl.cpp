
#include "appl.h"

QByteArray asas="";
QString st1, st2;
int k=0, yy[9], a[9] ,b[9], xx[9][4], q;
Appl1* appl2;

QTranslator veryTransUk;
QTranslator veryTransEn;
QTranslator veryTransRu;
bool switch1 = true;

Appl1::Appl1(QWidget* pwgt) : QWidget(pwgt)
{
  // фреймы
    fr1 = new QFrame;
    fr2 = new QFrame;
    fr21 = new QFrame;
    fr22 = new QFrame;
    fr20 = new QFrame;
    fr21->setMinimumWidth(200);
    fr22->setMinimumWidth(200);
    fr20->setMinimumWidth(410);
    //fr20->setMinimumHeight(170);

    l_try = new QLabel;
    QPalette pa3 = l_try->palette();
    pa3.setColor(l_try->foregroundRole(), Qt::darkCyan);
    l_try->setPalette(pa3);
    l_try->setAutoFillBackground(true);

    l_try->setFont(QFont("Arial",60,QFont::Normal));
    //l_try->setMinimumWidth(600);

        q = qrand() % 10;
    asas[0]=48+q;
    xx[k][0]=q;

    l01:q = qrand() % 10;
    asas[1]=48+q;
    if(asas[0]!=asas[1])        
        ;
    else goto l01;
    xx[k][1]=q;

    l02:q = qrand() % 10;
    asas[2]=48+q;
    if((asas[0]!=asas[2]) && (asas[1]!=asas[2]))
        ;
    else goto l02;
    xx[k][2]=q;

    l03:q = qrand() % 10;
    asas[3]=48+q;
    if((asas[0]!=asas[3]) && (asas[1]!=asas[3]) && (asas[2]!=asas[3]))
        ;
    else goto l03;
    xx[k][3]=q;

    //startString = new QString;

    ////////////////////////startString = "1234";
    l_try->setText(asas);//"1234");
    //l_try->setAlignment(Qt::AlignJustify);

    le1 = new QLineEdit;
    QPalette pal = le1->palette();
    pal.setColor(le1->foregroundRole(), Qt::darkBlue);
    le1->setPalette(pal);
    le1->setAutoFillBackground(true);
    le1->setTextMargins(3,3,3,3);
    le1->setFont(QFont("Arial",40,QFont::Normal));
    le1->setMaxLength(1);
    le1->setText("2");
    le1->setSelection(0,1);
    validator = new QIntValidator(0,4,this);    //можно ввести только цифры 0,1,2,3,4
    le1->setValidator(validator);
    le1->setMaximumWidth(42);

    le2 = new QLineEdit;
    QPalette pa2 = le2->palette();
    pa2.setColor(le2->foregroundRole(), Qt::darkBlue);
    le2->setPalette(pa2);
    le2->setAutoFillBackground(true);
    le2->setTextMargins(3,3,3,3);
    le2->setFont(QFont("Arial",40,QFont::Normal));
    le2->setMaxLength(1);
    le2->setText("1");

    validato2 = new QIntValidator(0,4,this);
    le2->setValidator(validato2);
    le2->setMaximumWidth(42);

    l_compa_m = new QLabel;
    l_compa_m->setText(
        "<p><span style=font-size:14pt><CENTER>"+
        QObject::tr("Compare this number with your number:")+
        "</span></p>"
        );

    l_compare = new QLabel;
    l_compare->setText(//"5555555"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("Enter")+
        "</span></p>"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("the number of digits,")+
        "</span></p>"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("the program correctly predicted:")+
        "</span></p>"
        );

    l_comp1_5 = new QLabel;
    l_comp1_5->setMinimumWidth(30);
    
    l_compar2 = new QLabel;
    l_compar2->setText(//"5555555"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("How many of them")+
        "</span></p>"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("stands")+
        "</span></p>"
        "<p><span style=font-size:16pt><CENTER>"+
        QObject::tr("in its place?")+
        "</span></p>"
        );

// начальный текст
    llll = new QLabel;
    llll->setText(
        "<p><span style=font-size:20pt><CENTER><font color=darkCyan>"+
        QObject::tr("Take a number")+
        "</span></p>"
        "<p><span style=font-size:20pt><CENTER><font color=darkCyan>"+
        QObject::tr("consisting of four")+
        "</span></p>"
        "<p><span style=font-size:20pt><CENTER><font color=darkCyan>"+
        QObject::tr("different digits.")+
        "</span></p>"
        "<p><span style=font-size:20pt><CENTER><font color=darkCyan>"+
        QObject::tr("I'm going to try to guess")+
        "</span></p>"
    );

    l_error = new QLabel;
    l_error->setText(
        "<p><span style=font-size:14pt><CENTER>"+
        QObject::tr("Error. Check your moves")+
        "</span></p>"
        );

    l_more = new QLabel;
    l_more->setText(
        "<p><span style=font-size:14pt><CENTER>"+
        QObject::tr("Play again?")+
        "</span></p>"
        );

    bttnStart = new QPushButton;
    bttnStart->setText(tr("Start"));    // Вогонь
    bttnNext = new QPushButton;
    bttnNext->setText(tr("Next"));      // Далі
    bttnMore = new QPushButton;
    bttnMore->setText(tr("More"));      // Ще
    bttnUk = new QPushButton;           // Uk
    //bttnEn->setText(tr("More"));
    bttnEn = new QPushButton;           // En
    bttnRu = new QPushButton;           // Ru

    QHBoxLayout* forUkLayout = new QHBoxLayout;
    QHBoxLayout* forEnLayout = new QHBoxLayout;
    QHBoxLayout* forRuLayout = new QHBoxLayout;
    QHBoxLayout* forllllLayout = new QHBoxLayout;
    QHBoxLayout* forbttnLayout = new QHBoxLayout;
    QHBoxLayout* forbttnnLayout = new QHBoxLayout;
    QHBoxLayout* forErrorLayout = new QHBoxLayout;
    QHBoxLayout* forMoreLayout = new QHBoxLayout;
    QHBoxLayout* forbttnmLayout = new QHBoxLayout;
    QVBoxLayout* startLayout = new QVBoxLayout;
    QHBoxLayout* h_for1Layout = new QHBoxLayout;
    QVBoxLayout* v_gameLayout = new QVBoxLayout;
    QHBoxLayout* h_framesLayout = new QHBoxLayout;
    h_framesLayout->setMargin(5);
    QHBoxLayout* fr21Layout = new QHBoxLayout;
    QHBoxLayout* fr22Layout = new QHBoxLayout;
    QHBoxLayout* fr20Layout = new QHBoxLayout;

    QVBoxLayout* infr21Layout = new QVBoxLayout;
    QVBoxLayout* infr22Layout = new QVBoxLayout;
    QVBoxLayout* infr20Layout = new QVBoxLayout;
    QHBoxLayout* forle1Layout = new QHBoxLayout;
    QHBoxLayout* forle2Layout = new QHBoxLayout;
    QHBoxLayout* forle3Layout = new QHBoxLayout;
//
    QVBoxLayout* forTableLayout = new QVBoxLayout;
//
    QHBoxLayout* h_blendLayout = new QHBoxLayout;
    QHBoxLayout* h_bttnLayout = new QHBoxLayout;


    pixUk = new QPixmap;
    pixEn = new QPixmap;
    pixRu = new QPixmap;
    pixUk->load("uk.png");
    pixEn->load("en.png");
    pixRu->load("ru.png");

    bttnUk->setIcon(*pixUk);
    bttnEn->setIcon(*pixEn);
    bttnRu->setIcon(*pixRu);

    table = new QTableWidget;
    table->setColumnCount(2);
    //table->setColumnWidth(0,75);
    table->setColumnWidth(1,70);
    table->setRowCount(7);
    table->setRowHeight(0,23);
    table->setRowHeight(1,23);
    table->setRowHeight(2,23);
    table->setRowHeight(3,23);
    table->setRowHeight(4,23);
    table->setRowHeight(5,23);
    table->setRowHeight(6,23);
    listTable = new QStringList;
    *listTable << "Number"<<"Result";
    table->setHorizontalHeaderLabels(*listTable);

    h_framesLayout->addWidget(fr1);
    h_framesLayout->addWidget(fr2);   
    fr20Layout->addWidget(fr20);
    fr21Layout->addWidget(fr21);
    fr22Layout->addWidget(fr22);

    fr1->setFrameStyle( QFrame::Raised | QFrame::Panel);
    fr1->setLineWidth(2);
    fr2->setFrameStyle( QFrame::Raised | QFrame::Panel);
    fr2->setLineWidth(2);
    setLayout(h_framesLayout);

    fr20->setFrameStyle( QFrame::Sunken | QFrame::Panel);
    fr20->setLineWidth(2);
    setLayout(fr20Layout);

    fr21->setFrameStyle( QFrame::Sunken | QFrame::Panel);
    fr21->setLineWidth(2);
    setLayout(fr21Layout);

    fr22->setFrameStyle( QFrame::Sunken | QFrame::Panel);
    fr22->setLineWidth(2);
    setLayout(fr22Layout);

// fr1
    //startLayout->addStretch(1);
        //h_bttnLayout->addStretch(1);
            //forUkLayout->addStretch(1);
            forUkLayout->addWidget(bttnUk);
            //forUkLayout->addStretch(1);
        h_bttnLayout->addLayout(forUkLayout);
        //h_bttnLayout->addStretch(1);
            //forEnLayout->addStretch(1);
            forEnLayout->addWidget(bttnEn);
            //forEnLayout->addStretch(1);
        h_bttnLayout->addLayout(forEnLayout);
        //h_bttnLayout->addStretch(1);
            //forEnLayout->addStretch(1);
            forRuLayout->addWidget(bttnRu);
            //forEnLayout->addStretch(1);
        h_bttnLayout->addLayout(forRuLayout);
        //h_bttnLayout->addStretch(1);
    startLayout->addLayout(h_bttnLayout);
//
    startLayout->addStretch(1);
        forllllLayout->addStretch(1);
        forllllLayout->addWidget(llll);
        forllllLayout->addStretch(1);
    startLayout->addLayout(forllllLayout);
    startLayout->addStretch(1);
        forbttnLayout->addStretch(1);
        forbttnLayout->addWidget(bttnStart);
        forbttnLayout->addStretch(1);
    startLayout->addLayout(forbttnLayout);
    startLayout->addStretch(1);

    fr1->setLayout(startLayout);
    //table->resize(20,30);

// fr2
    v_gameLayout->addStretch(1);
        h_blendLayout->addStretch(1);
            infr20Layout->addWidget(l_compa_m);
                forle3Layout->addStretch(1);
                forle3Layout->addWidget(l_try);
                forle3Layout->addStretch(1);
            infr20Layout->addLayout(forle3Layout);
        h_blendLayout->addLayout(fr20Layout);

        h_blendLayout->addStretch(1);
            //forTableLayout->addStretch(1);
            forTableLayout->addWidget(table);
            //forTableLayout->addStretch(1);
        h_blendLayout->addLayout(forTableLayout);

        h_blendLayout->addStretch(1);
    v_gameLayout->addLayout(h_blendLayout);

    v_gameLayout->addStretch(1);
        h_for1Layout->addStretch(1);
            infr21Layout->addWidget(l_compare);
                forle1Layout->addStretch(1);
                forle1Layout->addWidget(le1);
                forle1Layout->addStretch(1);
            infr21Layout->addLayout(forle1Layout);
        h_for1Layout->addLayout(fr21Layout);
        h_for1Layout->addWidget(l_comp1_5); //между первой (l_compare) и второй (l_compar2) промежуток небольшой
            infr22Layout->addWidget(l_compar2);
                forle2Layout->addStretch(1);
                forle2Layout->addWidget(le2);
                forle2Layout->addStretch(1);
            infr22Layout->addLayout(forle2Layout);
        h_for1Layout->addLayout(fr22Layout);
        h_for1Layout->addStretch(1);
    v_gameLayout->addLayout(h_for1Layout);
    //v_gameLayout->addStretch(1);
        forbttnnLayout->addStretch(1);
        forbttnnLayout->addWidget(bttnNext);
        forbttnnLayout->addStretch(1);
    v_gameLayout->addLayout(forbttnnLayout);
    //v_gameLayout->addStretch(1);
        forErrorLayout->addStretch(1);
        forErrorLayout->addWidget(l_error);
        forErrorLayout->addStretch(1);
    v_gameLayout->addLayout(forErrorLayout);
//
    //v_gameLayout->addStretch(1);
        forMoreLayout->addStretch(1);
        forMoreLayout->addWidget(l_more);
        forMoreLayout->addStretch(1);
    v_gameLayout->addLayout(forMoreLayout);
//
    v_gameLayout->addStretch(1);
        forbttnmLayout->addStretch(1);
        forbttnmLayout->addWidget(bttnMore);
        forbttnmLayout->addStretch(1);
    v_gameLayout->addLayout(forbttnmLayout);
    //v_gameLayout->addStretch(1);

    fr20->setLayout(infr20Layout);
    fr21->setLayout(infr21Layout);
    fr22->setLayout(infr22Layout);
    fr2->setLayout(v_gameLayout);
    fr2->hide();
    l_error->hide();
    l_more->hide();
    bttnMore->hide();

    bttnStart->setFocus(); //НЕ все одно фокус на кнопці, але активується пробілом
    //appl1.show();

    connect(bttnUk, SIGNAL(clicked()), SLOT(slotUkClicked()));
    connect(bttnEn, SIGNAL(clicked()), SLOT(slotEnClicked()));
    connect(bttnRu, SIGNAL(clicked()), SLOT(slotRuClicked()));
    connect(bttnStart, SIGNAL(clicked()), SLOT(slotStartClicked()));
    connect(bttnNext,  SIGNAL(clicked()), SLOT(slotNextClicked()));
    connect(bttnMore,  SIGNAL(clicked()), SLOT(slotMoreClicked()));

    connect(le1, SIGNAL(selectionChanged()), SLOT(selectionChanged21()));
    connect(le2, SIGNAL(selectionChanged()), SLOT(selectionChanged22()));

    connect(le1, SIGNAL(textEdited(const QString&)), SLOT(textEdited21()));
    connect(le2, SIGNAL(textEdited(const QString&)), SLOT(textEdited22()));
    //connect(le1, SIGNAL(textChanged()), SLOT(textChanged21()));
    //connect(le2, SIGNAL(textChanged()), SLOT(textChanged22()));

    veryTransUk.load("appl_Uk.qm",".");
    veryTransEn.load("appl_En.qm",".");
    veryTransRu.load("appl_Ru.qm",".");
}

// ----------------------------------------------------------------------

int fu(int l)
{
  int qq=0,aa,bb,i,j,m=0;
  do
  {
   aa=0;
   bb=0;
   for(i=0;i<=3;i++)
   {
    if (xx[l][i]==xx[m][i])
    bb++;
   }
   if (bb!=b[m])
   {
    qq=1;
    break;
   }
   for(i=0;i<=3;i++)
   {
    for(j=0;j<=3;j++)
    {
     if (xx[l][i]==xx[m][j])
     aa++;
    }
   }
   if (aa!=a[m])
   {
    qq=1;
    break;
   }
  }
  while(++m<l);
  return qq;
}

// ----------------------------------------------------------------------
void Appl1::selectionChanged22()
{
    qDebug() << "selectionChanged22" ;
}

void Appl1::textEdited22()
{
    st2 = le2->text();
    qDebug() << "textEdited22" ;
    if(st2.size())
    {
        bttnNext->setFocus();
    }
}


void Appl1::slotUkClicked()
{
    if(switch1)
    {
        qApp->installTranslator(&veryTransUk);
        appl2 = new Appl1;
        appl2->setWindowTitle("4-4");
        appl2->resize(640,460);
        appl2->show();
        delete appl1;
    }
    else
    {
        qApp->installTranslator(&veryTransUk);
        appl1 = new Appl1;
        appl1->setWindowTitle("4-4");
        appl1->resize(640,460);
        appl1->show();
        delete appl2;
    }
    switch1=!switch1;

    qDebug() << "slotUkClicked" << switch1;
}

void Appl1::slotEnClicked()
{
    if(switch1)
    {
        qApp->installTranslator(&veryTransEn);
        appl2 = new Appl1;
        appl2->setWindowTitle("4-4");
        appl2->resize(640,460);
        appl2->show();
        delete appl1;
    }
    else
    {
        qApp->installTranslator(&veryTransEn);
        appl1 = new Appl1;
        appl1->setWindowTitle("4-4");
        appl1->resize(640,460);
        appl1->show();
        delete appl2;
    }
    switch1=!switch1;
}

void Appl1::slotRuClicked()
{
    if(switch1)
    {
        qApp->installTranslator(&veryTransRu);
        appl2 = new Appl1;
        appl2->setWindowTitle("4-4");
        appl2->resize(640,460);
        appl2->show();
        delete appl1;
    }
    else
    {
        qApp->installTranslator(&veryTransRu);
        appl1 = new Appl1;
        appl1->setWindowTitle("4-4");
        appl1->resize(640,460);
        appl1->show();
        delete appl2;
    }
    switch1=!switch1;
}

void Appl1::slotStartClicked()
{
    fr1->hide();
    fr2->show();
    le1->setFocus();
    qDebug() << "slotStartClicked" ;
    qDebug() << "x[k][0]=" << xx[k][0];
    qDebug() << "x[k][1]=" << xx[k][1];
    qDebug() << "x[k][2]=" << xx[k][2];
    qDebug() << "x[k][3]=" << xx[k][3];
}

void Appl1::slotMoreClicked()
{
    qDebug() << "slotMoreClicked";
    fr2->hide();
    fr1->show();
    bttnStart->setFocus();
   xx[0][0] = xx[k-1][0];
   asas[0]=48+xx[0][0];
   xx[0][1] = xx[k-1][1];
   asas[1]=48+xx[0][1];
   xx[0][2] = xx[k-1][2];
   asas[2]=48+xx[0][2];
   xx[0][3] = xx[k-1][3];
   asas[3]=48+xx[0][3];
    k=0;
    l_error->hide();
    l_more->hide();
    bttnMore->hide();
    fr21->show();
    fr22->show();
    bttnNext->show();
    table->clear();
    table->setHorizontalHeaderLabels(*listTable);
    le1->setSelection(0,1);
}

void Appl1::selectionChanged21()
{
    qDebug() << "selectionChanged21";
}

void Appl1::textEdited21()
{    
    st1 = le1->text();
    qDebug() << "textEdited21" << st1.size();
    if(st1.size())
    {
        le2->setFocus();
        le2->setSelection(0,1);
    }
}

void Appl1::slotNextClicked()
{
    int z, o=0, asdf;
    QString xxxx,yyyy,zzzz;

    le1->setFocus();
    le1->setSelection(0,1);
    qDebug() << "slotNextClicked" ;
    xxxx=le1->text();
    yyyy=le2->text();
    a[k]=xxxx.toInt();
    b[k]=yyyy.toInt();
    yy[k]=xx[k][0] * 1000 + xx[k][1] * 100 + xx[k][2] * 10 + xx[k][3];

    //qDebug() << "x[k][0]=" << xx[k][0];
    //qDebug() << "x[k][1]=" << xx[k][1];
    //qDebug() << "x[k][2]=" << xx[k][2];
    //qDebug() << "x[k][3]=" << xx[k][3];
    //qDebug() << "yy[k]=" << yy[k];
    zzzz = asas;
    table->setItem(k, 0,new QTableWidgetItem(zzzz));
    table->setItem(k, 1,new QTableWidgetItem(xxxx+":"+yyyy));
    qDebug() << "b[k]=" << b[k];
    qDebug() << "k=" << k;
    if(b[k]==4)
        goto l04;

    k++;

    //ite++;
    yy[k]=yy[k-1];
    c:   q=0;
    if (yy[k]==9876)
    {
        yy[k]=122;
        o++;
    }
    //qDebug() << "o=" << o;
    if (o==2)
        //break
        goto l02;
    z=++yy[k];
    for (int i=0,r2=1000;i<=3;i++)
    {
        xx[k][i]=z/r2;
        z=z-z/r2*r2;
        r2=r2/10;
    }
    for (int i=1;i<=3;i++)
    {
        for (int j=0;j<=i-1;j++)
        {
            if (xx[k][i]==xx[k][j])
            {
                q=1;
                //break;
            }
        }
        //if (q==1)
            //break;
    }
    if (q==1)
    goto c;

    q=fu(k);
    if (q==1)
    goto c;
    //qDebug() << "yy[k]=" << yy[k];
    asdf = yy[k];
    xx[k][3] = asdf%10;
    asas[3] = xx[k][3]+48;
    asdf = asdf/10;
    xx[k][2] = asdf%10;
    asas[2] = xx[k][2]+48;
    asdf = asdf/10;
    xx[k][1] = asdf%10;
    asas[1] = xx[k][1]+48;
    asdf = asdf/10;
    xx[k][0] = asdf%10;
    asas[0] = xx[k][0]+48;
    asdf = asdf/10;
    //qDebug() << "x[k][0]=" << xx[k][0];
    //qDebug() << "x[k][1]=" << xx[k][1];
    //qDebug() << "x[k][2]=" << xx[k][2];
    //qDebug() << "x[k][3]=" << xx[k][3];
    l_try->setText(asas);
    goto l03;
    l02: qDebug() << "The End";
    l_error->show();
    l04: bttnNext->hide();
    fr21->hide();
    fr22->hide();
    l_more->show();
    bttnMore->show();
    bttnMore->setFocus();
    l03: ;
}

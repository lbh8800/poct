#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);

    ui->btReset->setIconMainPath(":/res/png/p2b1reset");
    ui->btClean->setIconMainPath(":/res/png/p2b2clean");
    ui->btSys->setIconMainPath(":/res/png/p2b3sys");
    ui->btTrans->setIconMainPath(":/res/png/p2b4trans");
    ui->btPrint->setIconMainPath(":/res/png/p2b5print");
    ui->btPlot->setIconMainPath(":/res/png/p2b6plot");
    ui->btToMain->setIconMainPath(":/res/png/p2b7toMain");

    ui->btT1->setIconMainPath(":/res/png/p2b0");
    ui->btT1->setTypeIconPath(":/res/png/T1");
    ui->btT1->setLockOpenIconPath(":/res/png/lockOpen");
    ui->btT1->setLockCloseIconPath(":/res/png/lockClose");
    ui->btT1->setPointPinkIconPath(":/res/png/pointPink");
    ui->btT1->setPointGreenIconPath(":/res/png/pointGreen");
    ui->btT1->setActionEnable(true);
    ui->btT1->setTypeCode(typeT1);

    ui->btT2->setIconMainPath(":/res/png/p2b0");
    ui->btT2->setTypeIconPath(":/res/png/T2");
    ui->btT2->setLockOpenIconPath(":/res/png/lockOpen");
    ui->btT2->setLockCloseIconPath(":/res/png/lockClose");
    ui->btT2->setPointPinkIconPath(":/res/png/pointPink");
    ui->btT2->setPointGreenIconPath(":/res/png/pointGreen");
    ui->btT2->setActionEnable(true);
    ui->btT2->setTypeCode(typeT2);

    ui->btT3->setIconMainPath(":/res/png/p2b0");
    ui->btT3->setTypeIconPath(":/res/png/T3");
    ui->btT3->setLockOpenIconPath(":/res/png/lockOpen");
    ui->btT3->setLockCloseIconPath(":/res/png/lockClose");
    ui->btT3->setPointPinkIconPath(":/res/png/pointPink");
    ui->btT3->setPointGreenIconPath(":/res/png/pointGreen");
    ui->btT3->setActionEnable(false);

    ui->btT4->setIconMainPath(":/res/png/p2b0");
    ui->btT4->setTypeIconPath(":/res/png/T4");
    ui->btT4->setLockOpenIconPath(":/res/png/lockOpen");
    ui->btT4->setLockCloseIconPath(":/res/png/lockClose");
    ui->btT4->setPointPinkIconPath(":/res/png/pointPink");
    ui->btT4->setPointGreenIconPath(":/res/png/pointGreen");
    ui->btT4->setActionEnable(false);

    ui->btQ1->setIconMainPath(":/res/png/p2b0");
    ui->btQ1->setTypeIconPath(":/res/png/Q1");
    ui->btQ1->setLockOpenIconPath(":/res/png/lockOpen");
    ui->btQ1->setLockCloseIconPath(":/res/png/lockClose");
    ui->btQ1->setPointPinkIconPath(":/res/png/pointPink");
    ui->btQ1->setPointGreenIconPath(":/res/png/pointGreen");
    ui->btQ1->setActionEnable(true);
    ui->btQ1->setTypeCode(typeQ1);

    dataProcess = new DataProcess();

    connect(ui->btT1,SIGNAL(sendDataSignal(ushort, ushort)),dataProcess,SLOT(sendData(ushort, ushort)));
    connect(ui->btT2,SIGNAL(sendDataSignal(ushort, ushort)),dataProcess,SLOT(sendData(ushort, ushort)));
    connect(ui->btT3,SIGNAL(sendDataSignal(ushort, ushort)),dataProcess,SLOT(sendData(ushort, ushort)));
    connect(ui->btT4,SIGNAL(sendDataSignal(ushort, ushort)),dataProcess,SLOT(sendData(ushort, ushort)));
    connect(ui->btQ1,SIGNAL(sendDataSignal(ushort, ushort)),dataProcess,SLOT(sendData(ushort, ushort)));

    ui->btT3->hide();
    ui->btT4->hide();
}

Test::~Test()
{
    delete ui;
}
void Test::resizeEvent(QResizeEvent *)
{
    setBackgroundImage(m_pixmap);
}

void Test::setBackgroundImage(QPixmap &pixmap)
{
    if(pixmap.isNull())
    {
        return;
    }
    m_pixmap = pixmap;
    QPalette palette = this->palette();
    palette.setBrush(this->backgroundRole(),
                     QBrush(pixmap.scaled(this->size(),
                                          Qt::IgnoreAspectRatio,
                                          Qt::SmoothTransformation)));
    this->setPalette(palette);
}

void Test::on_btToMain_clicked()
{
    emit toMainSignal();
}

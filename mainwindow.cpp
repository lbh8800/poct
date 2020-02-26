#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btTest->setIconMainPath(":/res/png/p1b1test");
    ui->btQc->setIconMainPath(":/res/png/p1b2qc");
    ui->btSet->setIconMainPath(":/res/png/p1b3set");
    ui->btQuery->setIconMainPath(":/res/png/p1b4que");

    test = new Test();
    test->setAutoFillBackground(true);
    QPixmap pixmap(":/res/png/p2back");
    test->setBackgroundImage(pixmap);

    connect(test,SIGNAL(toMainSignal()),this,SLOT(showMain()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMain()
{
    this->showFullScreen();
    test->hide();
}

void MainWindow::on_btTest_clicked()
{
    test->showFullScreen();
    this->hide();
}

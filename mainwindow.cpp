#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <formguitar.h>
//#include <formpiano.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    FormGuitar *formguitar = new FormGuitar();
    formguitar->show();
}


//void MainWindow::on_pushButton_2_clicked()
//{
//    FormPiano *formpiano = new FormPiano();
//    formpiano->show();
//}





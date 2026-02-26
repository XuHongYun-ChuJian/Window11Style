#include "mainwindow.h"

#include "cusproxystyle.h"
#include "ui_mainwindow.h"

#include <QStyleFactory>
#include <QStyleHints>

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("MainWindow{background: white;}");//rgb(243,243,243);
    ui->setupUi( this );

    ui->tableWidget->verticalHeader()->setMinimumSectionSize(32);
}

MainWindow::~MainWindow()
{
    delete ui;
}

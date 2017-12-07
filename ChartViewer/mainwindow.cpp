#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, QString(), QString(), "Text Files (*.txt);;All Files (*.*)");
    if(!filePath.isEmpty()){
        ui->centralWidget->chartDoc.loadChartFromFile(filePath);
        this->setFixedWidth(90 + 160*ui->centralWidget->chartDoc.getSize());
    }

}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, QString(), QString(), "Text Files (*.txt);;All Files (*.*)");
    if(!filePath.isEmpty())
    {
        ui->centralWidget->chartDoc.saveChartToFile(filePath);
    }
}

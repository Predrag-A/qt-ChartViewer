#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->ptr = &m_chartDoc;
     connect(&m_chartDoc,SIGNAL(chartDataChanged()),ui->centralWidget,SLOT(onChartDataChanged()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, QString(), QString(), "Text Files (*.txt);;All Files (*.*)");
    if(!filePath.isEmpty()){
        m_chartDoc.loadChartFromFile(filePath);
        this->setFixedWidth(90 + 160*m_chartDoc.getSize());
    }

}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, QString(), QString(), "Text Files (*.txt);;All Files (*.*)");
    if(!filePath.isEmpty())
    {
        m_chartDoc.saveChartToFile(filePath);
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chartdoc.h"
#include "chartview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_triggered();
    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    ChartDoc m_chartDoc;
};

#endif // MAINWINDOW_H

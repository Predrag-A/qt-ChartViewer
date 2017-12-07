#ifndef CHARTPOINTDIALOG_H
#define CHARTPOINTDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "chartpoint.h"

namespace Ui {
class ChartPointDialog;
}

class ChartPointDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChartPointDialog(QWidget *parent = 0);
    ~ChartPointDialog();

    void SetValues(ChartPoint*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChartPointDialog *ui;

    ChartPoint* _pt;
    QString _oldLabel;
    float _oldValue;
    QColor _oldColor;
};

#endif // CHARTPOINTDIALOG_H

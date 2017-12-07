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
    inline QString GetLabel(){ return _label; }
    inline float GetValue() { return _value; }
    inline QColor GetColor() { return _color; }

private slots:
    void on_pushButton_clicked();
    void on_txtValue_textChanged(const QString &arg1);
    void on_txtLabel_textChanged(const QString &arg1);

private:
    Ui::ChartPointDialog *ui;

    QString _label;
    float _value;
    QColor _color;
};

#endif // CHARTPOINTDIALOG_H

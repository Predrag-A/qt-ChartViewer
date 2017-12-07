#include "chartpointdialog.h"
#include "ui_chartpointdialog.h"

ChartPointDialog::ChartPointDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartPointDialog)
{
    ui->setupUi(this);
}

ChartPointDialog::~ChartPointDialog()
{
    delete ui;
}

void ChartPointDialog::SetValues(ChartPoint *pt)
{
    _pt = pt;
    _oldColor = _pt->GetColor();
    _oldLabel = _pt->GetLabel();
    _oldValue = _pt->GetValue();

    ui->txtColor->setText(_pt->GetColor().name());
    ui->txtLabel->setText(pt->GetLabel());
    ui->txtValue->setText(QString::number(pt->GetValue()));
}

void ChartPointDialog::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    ui->txtColor->setText(color.name());
    _pt->SetColor(color);
}

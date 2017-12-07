#include "chartpointdialog.h"
#include "ui_chartpointdialog.h"

ChartPointDialog::ChartPointDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartPointDialog)
{
    ui->setupUi(this);
    ui->txtValue->setValidator(new QDoubleValidator(0,10000,10,this));
}

ChartPointDialog::~ChartPointDialog()
{
    delete ui;
}

void ChartPointDialog::SetValues(ChartPoint *pt)
{
    _color = pt->GetColor();
    _label = pt->GetLabel();
    _value = pt->GetValue();

    ui->txtColor->setText(_color.name());
    ui->txtLabel->setText(_label);
    ui->txtValue->setText(QString::number(_value));
}

void ChartPointDialog::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    ui->txtColor->setText(color.name());
    _color=color;
}

void ChartPointDialog::on_txtValue_textChanged(const QString &arg1)
{
    _value = ui->txtValue->text().toFloat();
}

void ChartPointDialog::on_txtLabel_textChanged(const QString &arg1)
{
    _label = ui->txtLabel->text();
}

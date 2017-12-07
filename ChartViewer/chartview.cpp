#include "chartview.h"

ChartView::ChartView(QWidget *parent) : QWidget(parent)
{

}

void ChartView::onChartDataChanged()
{
    this->update();
}

void ChartView::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QFont font("Helvetica");
    font.setPixelSize(20);
    p.setRenderHint(QPainter::Antialiasing);
    p.setFont(font);

    ptr->Draw(p);
}

void ChartView::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(ptr->getSize() <= 0)
        return;
    ChartPointDialog dlg;
    int count = 0;
    if(ptr->getSize() != 1){
        int xCoord = e->pos().x(), start = 210;
        while(xCoord > start && count < ptr->getSize()-1){
            start+=160;
            count++;
        }
    }
    dlg.SetValues(ptr->getPoint(count));
    if(dlg.exec() == QDialog::Accepted)
        ptr->ChangePoint(count, dlg.GetLabel(),dlg.GetValue(),dlg.GetColor());

}

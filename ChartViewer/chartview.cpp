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

    chartDoc.Draw(p);
}

void ChartView::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(chartDoc.getSize() <= 0)
        return;
    ChartPointDialog dlg;
    int count = 0;
    if(chartDoc.getSize() != 1){
        int xCoord = e->pos().x(), start = 210, count = 0;
        while(xCoord > start && count < chartDoc.getSize()-1){
            start+=160;
            count++;
        }
    }
    dlg.SetValues(chartDoc.getPoint(count));
    if(dlg.exec() == QDialog::Accepted){
        this->update();
    }

}

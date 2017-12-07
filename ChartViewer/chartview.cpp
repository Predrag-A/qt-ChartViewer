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
    QColor c;
    c.setNamedColor("#ffffff");
    if(chartDoc.getSize() == 1){
        //Edit first
        chartDoc.getPoint(0)->SetColor(c);
    }
    else{
        int xCoord = e->pos().x(), start = 210, count = 0;
        while(xCoord > start && count < chartDoc.getSize()){
            start+=160;
            count++;
        }
        if(count == chartDoc.getSize())
            chartDoc.getPoint(count-1)->SetColor(c);
        else
            chartDoc.getPoint(count)->SetColor(c);
    }
    this->update();

}

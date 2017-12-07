#include "chartview.h"

ChartView::ChartView(QWidget *parent) : QWidget(parent)
{

}

void ChartView::onChartDataChanged()
{


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

}

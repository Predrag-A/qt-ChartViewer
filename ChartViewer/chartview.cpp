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
    p.setRenderHint(QPainter::Antialiasing);

    chartDoc.Draw(p);
}

void ChartView::mouseDoubleClickEvent(QMouseEvent *e)
{

}

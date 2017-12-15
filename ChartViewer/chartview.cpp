#include "chartview.h"

ChartView::ChartView(QWidget *parent) : QWidget(parent)
{
    view3D = false;
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
    p.setFont(font);
    p.setRenderHint(QPainter::Antialiasing);
    p.fillRect(rect(),Qt::white);

    if(view3D)
        ptr->Draw3D(p);
    else
        ptr->Draw2D(p);
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

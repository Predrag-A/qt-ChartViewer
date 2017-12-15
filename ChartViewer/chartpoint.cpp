#include "chartpoint.h"

ChartPoint::ChartPoint()
{
   _value = 0;
}

ChartPoint::ChartPoint(QString label, float value, QColor color)
{
    _label = label;
    _value = value;
    _color = color;
}

void ChartPoint::SetLabel(QString label)
{
    _label = label;
}

void ChartPoint::SetValue(float value)
{
    _value = value;
}

void ChartPoint::SetColor(QColor color)
{
    _color = color;
}

void ChartPoint::DrawPoint2D(QPainter& p, int index, float percent)
{
    p.setBrush(_color);
    p.drawRect(150*index + 50 + 10*index, 50 + (400-400*percent), 150, 400*percent);
    p.drawText(150*index + 130 + 10*index - _label.size()*6, 475, _label);

}

void ChartPoint::DrawPoint3D(QPainter& p, int index, float percent)
{
    this->DrawPoint2D(p,index,percent);
    p.drawText(150*index + 130 + 10*index - QString::number(_value).size()*6, 30+(400-400*percent), QString::number(_value));

    QPointF points1[4] = {
        QPointF(150*index+50+10*index, 50+(400-400*percent)),
        QPointF(150*index+50+10*index, 50+400),
        QPointF(150*index+50+10*index -30 , 50+400-10),
        QPointF(150*index+50+10*index -30, 50+(400-400*percent) -10)
    };
    p.drawConvexPolygon(points1,4);

    QPointF points2[4] = {
        QPointF(150*index+50+10*index, 50+(400-400*percent)),
        QPointF(150*(index+1)+50+10*index, 50+(400-400*percent)),
        QPointF(150*(index+1)+50+10*index -30, 50+(400-400*percent) -10),
        QPointF(150*index+50+10*index -30, 50+(400-400*percent) -10),
    };
    p.drawConvexPolygon(points2,4);

}

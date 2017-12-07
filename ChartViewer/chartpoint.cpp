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

void ChartPoint::DrawPoint(QPainter& p, int index, float percent)
{
    p.setBrush(_color);
    p.drawRect(150*index + 50 + 10*index, 50 + (400-400*percent), 150, 400*percent);
    p.drawText(150*index + 130 + 10*index - _label.size()*6, 475, _label);
}

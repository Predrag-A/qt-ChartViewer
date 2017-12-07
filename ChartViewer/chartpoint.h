#ifndef CHARTPOINT_H
#define CHARTPOINT_H

#include <QString>
#include <QColor>
#include <QPainter>


class ChartPoint
{
public:
    ChartPoint();
    ChartPoint(QString, float, QColor);

    void SetLabel(QString);
    void SetValue(float);
    void SetColor(QColor);

    inline QString GetLabel(){ return _label; }
    inline float GetValue(){ return _value; }
    inline QColor GetColor(){ return _color; }

    void DrawPoint(QPainter&, int, float);

private:
    QString _label;
    float _value;
    QColor _color;


};

#endif // CHARTPOINT_H

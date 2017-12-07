#ifndef CHARTPOINT_H
#define CHARTPOINT_H

#include <QString>
#include <QColor>


class ChartPoint
{
public:
    ChartPoint();
    ChartPoint(QString, float, QColor);

    void SetLabel(QString);
    void SetValue(float);
    void SetColor(QColor);

    inline const QString GetLabel(){ return _label; }
    inline const float GetValue(){ return _value; }
    inline const QColor GetColor(){ return _color; }

private:
    QString _label;
    float _value;
    QColor _color;


};

#endif // CHARTPOINT_H

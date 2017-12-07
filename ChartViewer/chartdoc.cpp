#include "chartdoc.h"

ChartDoc::ChartDoc(QObject *parent) : QObject(parent)
{
    if(_points.size() > 0)
        for(int i=0;i<_points.size();i++)
            delete _points[i];
}

void ChartDoc::loadChartFromFile(QString filePath)
{
    QFile f(filePath);

    if(f.open(QIODevice::ReadOnly)){

        QTextStream in(&f);

        QString line = in.readLine();
        while(!line.isNull()){
            QStringList pointList = line.split(",");
            QColor c;
            c.setNamedColor(pointList[2]);

            _points.append(new ChartPoint(pointList[0],pointList[1].toDouble(),c));
            line = in.readLine();
        }
    }

    f.close();
}

void ChartDoc::saveChartToFile(QString filePath)
{
    QFile f(filePath);

    if(f.open(QIODevice::WriteOnly)){

        QTextStream out(&f);

        for(int i=0;i<_points.size();i++)
            out << _points[i]->GetLabel() << "," << _points[i]->GetValue() << "," << _points[i]->GetColor().name() << "\r\n";
    }

    f.close();

}

void ChartDoc::Draw(QPainter& p)
{
    float max = getMaxValue();
    for(int i=0;i<_points.size();i++){
        float percent = _points[i]->GetValue()/max;
        _points[i]->DrawPoint(p, i, percent);
    }
}

float ChartDoc::getMaxValue()
{
    if(_points.size() == 0)
        return -1;
    float max = _points[0]->GetValue();
    for(int i=1;i<_points.size();i++)
        if(_points[i]->GetValue()>max)
            max = _points[i]->GetValue();
    return max;
}

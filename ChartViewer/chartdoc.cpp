#include "chartdoc.h"

ChartDoc::ChartDoc(QObject *parent) : QObject(parent)
{

}

void ChartDoc::loadChartFromFile(QString filePath)
{
    QFile f(filePath);

    if(f.open(QIODevice::ReadOnly)){

        QTextStream in(&f);
        QString line = in.readLine();
        while(!line.isNull()){
            ChartPoint* temp = new ChartPoint();
            QColor c;
            QStringList pointList = line.split(",");
            c.setNamedColor(pointList[2]);

            temp->SetLabel(pointList[0]);
            temp->SetValue(pointList[1].toDouble());
            temp->SetColor(c);

            _points.append(temp);
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

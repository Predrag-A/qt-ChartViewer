#include "chartdoc.h"
#include "QFile"

ChartDoc::ChartDoc(QObject *parent) : QObject(parent)
{
    if(m_points.size() > 0)
        for(int i=0;i<m_points.size();i++)
            delete m_points[i];
}

void ChartDoc::loadChartFromFile(QString filePath)
{
    m_points.clear();

    QFile f(filePath);

    if(f.open(QIODevice::ReadOnly)){

        QTextStream in(&f);

        QString line = in.readLine();
        while(!line.isNull()){
            QStringList pointList = line.split(",");
            QColor c;
            c.setNamedColor(pointList[2]);

            m_points.append(new ChartPoint(pointList[0],pointList[1].toDouble(),c));
            line = in.readLine();
        }
    }

    f.close();
    emit chartDataChanged();
}

void ChartDoc::saveChartToFile(QString filePath)
{
    QFile f(filePath);

    if(f.open(QIODevice::WriteOnly)){

        QTextStream out(&f);

        for(int i=0;i<m_points.size();i++)
            out << m_points[i]->GetLabel() << "," << m_points[i]->GetValue() << "," << m_points[i]->GetColor().name() << "\r\n";
    }

    f.close();

}

void ChartDoc::Draw2D(QPainter& p)
{
    if(m_points.size() == 0)
        return;
    float max = getMaxValue();
    for(int i=0;i<m_points.size();i++){
        float percent = m_points[i]->GetValue()/max;
        m_points[i]->DrawPoint2D(p, i, percent);
    }
    for(int i=0;i<11;i++){
        p.drawLine(15, i*40+50, 50, i*40+50);
        p.drawText(5, i*40+45, QString::number(max - max*i/10));
    }

}

void ChartDoc::Draw3D(QPainter& p)
{
    if(m_points.size() == 0)
        return;
    float max = getMaxValue();
    for(int i=m_points.size()-1;i>=0;i--){
        float percent = m_points[i]->GetValue()/max;
        m_points[i]->DrawPoint3D(p, i, percent);
    }
}

float ChartDoc::getMaxValue()
{
    if(m_points.size() == 0)
        return -1;
    float max = m_points[0]->GetValue();
    for(int i=1;i<m_points.size();i++)
        if(m_points[i]->GetValue()>max)
            max = m_points[i]->GetValue();
    return max;
}

ChartPoint *ChartDoc::getPoint(int index)
{
    return m_points[index];
}

void ChartDoc::ChangePoint(int index, QString label, float value, QColor color)
{
    m_points[index]->SetLabel(label);
    m_points[index]->SetColor(color);
    m_points[index]->SetValue(value);

    emit chartDataChanged();
}

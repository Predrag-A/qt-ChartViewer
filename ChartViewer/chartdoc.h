#ifndef CHARTDOC_H
#define CHARTDOC_H

#include <QObject>
#include <QList>
#include <QTextStream>
#include <iostream>
#include "chartpoint.h"

class ChartDoc : public QObject
{
    Q_OBJECT
public:
    explicit ChartDoc(QObject *parent = nullptr);

    void loadChartFromFile(QString);
    void saveChartToFile(QString);
    void Draw2D(QPainter&);
    void Draw3D(QPainter&);

    void ChangePoint(int, QString, float, QColor);
    inline int getSize(){ return m_points.size(); }
    float getMaxValue();
    ChartPoint *getPoint(int);

signals:
    void chartDataChanged();

public slots:

private:
    QList<ChartPoint*> m_points;

};

#endif // CHARTDOC_H

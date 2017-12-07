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
    void Draw(QPainter&);
    inline int getSize(){ return _points.size(); }
    float getMaxValue();
    ChartPoint *getPoint(int);

signals:
    void chartDataChanged();

public slots:

private:
    QList<ChartPoint*> _points;

};

#endif // CHARTDOC_H

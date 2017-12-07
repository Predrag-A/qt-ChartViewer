#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include "chartdoc.h"

class ChartView : public QWidget
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = nullptr);
    ChartDoc chartDoc;

signals:

public slots:
};

#endif // CHARTVIEW_H

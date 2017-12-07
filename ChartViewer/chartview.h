#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include "chartpointdialog.h"
#include "chartdoc.h"

class ChartView : public QWidget
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = nullptr);
    ChartDoc* ptr;

signals:

public slots:
    void onChartDataChanged();

protected:
    void paintEvent(QPaintEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);

};

#endif // CHARTVIEW_H

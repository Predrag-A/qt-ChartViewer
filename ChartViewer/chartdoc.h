#ifndef CHARTDOC_H
#define CHARTDOC_H

#include <QObject>

class ChartDoc : public QObject
{
    Q_OBJECT
public:
    explicit ChartDoc(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHARTDOC_H
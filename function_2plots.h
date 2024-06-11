#pragma once

#include <vector>

#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QMainWindow>
#include <QVector>
#include <QWidget>

// include all the plotting stuff
#include <QChart>
#include <QtCharts>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>

void plotGraph2(QWidget *parent, const std::vector<double>& y1, const std::vector<double>& y2, const std::vector<double>& time, const std::vector <QString>& plotlabel) {
    if (!parent) {
        qDebug() << "plotGraph: Provide non-null parent";
        return;
    }

    if (!parent->layout()) {
        qDebug() << "plotGraph: Provide parent which has layout";
        return;
    }

    // Check that the input vectors are not empty
    if (y1.empty()  || y2.empty()  ||  time.empty()) {
        qDebug() << "Error: One or more input vectors are empty";
        return;
    }

    if (plotlabel.empty()) {
        qDebug() << "Error: No plot labels";
        return;
    }

    // Check that the input vectors have the same size
    if (y1.size() != time.size()  || y2.size() != time.size()  || y1.size() != y2.size()) {
        qDebug() << "Error: The input vectors have different sizes";
        return;
    }

    if (plotlabel.size() != 2) {
        qDebug() << "Error: The input plot label isn't correct";
        return;
    }

    // Create a chart
    QChart *chart = new QChart();

    // Create x-axis (time)
    QValueAxis *axisX = new QValueAxis();

    // Create y-axis
    QValueAxis *axisY = new QValueAxis();

    // Set axis titles
    axisX->setTitleText(plotlabel[0]);
    axisY->setTitleText(plotlabel[1]);

    // Add axes to the chart
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // Create a line series
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();

    // Fill the series with data from vectors
    for (size_t i = 0; i < y1.size(); ++i) {
        series1->append(time[i], y1[i]);
        series2->append(time[i], y2[i]);
    }

    // Add series to the chart
    chart->addSeries(series1);
    chart->addSeries(series2);

    // Attach series to axes
    series1->attachAxis(axisX);
    series1->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);

    // Create a chart view
    auto view = new QChartView(parent);
    view->setMinimumSize(400, 300);
    view->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    view->setChart(chart);

    parent->layout()->addWidget(view);
    view->show();
}
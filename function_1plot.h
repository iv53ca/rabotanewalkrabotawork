#pragma once

#include <vector>

#include <QApplication>
#include <QBoxLayout>
#include <QDebug>
#include <QMainWindow>
#include <QVector>
#include <QWidget>

// include all the plotting stuff
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>

class GraphPlotter {
public:
    GraphPlotter(const std::vector<double>& y, const std::vector<double>& x)
            : y_(y), x_(x) {}

    QChartView* plotGraph1(QWidget* parent) {
        if (!parent) {
            qDebug() << "plotGraph: Provide non-null parent";
            return nullptr;
        }

        if (y_.empty() || x_.empty()) {
            qDebug() << "Error: One or more input vectors are empty";
            return nullptr;
        }

        if (y_.size() != x_.size()) {
            qDebug() << "Error: The input vectors have different sizes";
            return nullptr;
        }

        QChart* chart = new QChart();
        chart->setTitle("Linear plot");

        QValueAxis* axisX = new QValueAxis();
        axisX->setTitleText("X");
        chart->addAxis(axisX, Qt::AlignBottom);

        QValueAxis* axisY = new QValueAxis();
        axisY->setTitleText("Y");
        chart->addAxis(axisY, Qt::AlignLeft);

        QLineSeries* series = new QLineSeries();
        for (size_t i = 0; i < y_.size(); ++i) {
            series->append(x_[i], y_[i]);
        }
        chart->addSeries(series);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

        QChartView* chartView = new QChartView(chart, parent);
        chartView->setMinimumSize(400, 300);
        chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        return chartView;
    }

private:
    std::vector<double> y_;
    std::vector<double> x_;
};
/* 
 * File:   SplineGenerator.cpp
 * Author: matt
 * 
 * Created on 09 June 2010, 18:55
 */

#include <qt4/QtCore/qobject.h>

#include "SplineGenerator.h"

SplineGenerator::SplineGenerator() {
    layout = new QGridLayout(this);
    threshold_min = 30;
    threshold_max = 255;
    threshold_min_spinbox = new QSpinBox();
    threshold_max_spinbox = new QSpinBox();
    threshold_min_spinbox->setRange(0, 255);
    threshold_max_spinbox->setRange(0, 255);
    threshold_min_spinbox->setValue(threshold_min);
    threshold_max_spinbox->setValue(threshold_max);
    layout->addWidget(new QLabel("Spline Generator Settings"), 0, 0, 1, 3);
    layout->addWidget(new QLabel("Threshold Max"), 1, 0);
    layout->addWidget(threshold_max_spinbox, 1, 1);
    layout->addWidget(new QLabel("Threshold Min"), 1, 2);
    layout->addWidget(threshold_min_spinbox, 1, 3);
    connect(threshold_max_spinbox, SIGNAL(valueChanged(int)), this, SLOT(setMaxThreshold(int)));
    connect(threshold_min_spinbox, SIGNAL(valueChanged(int)), this, SLOT(setMinThreshold(int)));
}

SplineGenerator::~SplineGenerator() {
}

QVector<int> SplineGenerator::process(QImage passed) {

    image = passed;
    //threshold the image
    threshold();
    //find the maximum value along the horizontal axis
    calcHorixontalValue();

    return points;
}

void SplineGenerator::threshold() {
    //Flatten the image down to the red channel and threshold the image
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QRgb pixel = image.pixel(x, y);
            double max = 0;
            if (qRed(pixel) > max)max = qRed(pixel);
            if (qGreen(pixel) > max)max = qGreen(pixel);
            if (qBlue(pixel) > max)max = qBlue(pixel);
            if (max < threshold_min)max = 0;
            if (max > threshold_max)max = 255;
            pixel = qRgb(max, 0, 0);
            image.setPixel(x, y, pixel);
        }
    }

}

void SplineGenerator::setMaxThreshold(int passed) {
    threshold_max = passed;
    threshold_min_spinbox->setRange(0, threshold_max);
    cerr << "Setting max threshold to: " << passed << endl;
}

void SplineGenerator::setMinThreshold(int passed) {
    threshold_min = passed;
    threshold_max_spinbox->setRange(threshold_min, 255);
    cerr << "Setting min threshold to: " << passed << endl;
}

void SplineGenerator::calcHorixontalValue() {

    QVector<int> current;
    for (int y = image.height() - 1; y >= 0; y--) {
        //Find the position of the first x value along a each line
        int x_value = 0;
        int x_max = threshold_min + 1;
        QRgb pixel;
        for (int x = 0; x < image.width(); x++) {
            pixel = image.pixel(x, y);
            if (qRed(pixel) >= x_max) {
                x_value = x;
                break;
            }
        }
        if (x_value > 0)image.setPixel(x_value, y, qRgb(255, 255, 255));

    }

    QImage *image2 = new QImage(image.width(), image.height(), QImage::Format_RGB32);
    image2->fill(qRgb(0, 0, 0));
    QPainter image_painter(image2);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(255, 255, 255));
    image_painter.setPen(pen);

    QPoint point1;
    QPoint point2;
    point1.setX(image.width() / 2);
    point1.setY(0);
    point2.setX(image.width() / 2);
    point2.setY(0);
    bool new_point = false;
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QRgb pixel = image.pixel(x, y);
            int value = qRed(pixel);
            if (value == 255) {
                point1.setY(y);
                point1.setX(x);
                new_point = true;
            }
        }

        if (new_point == true) {
            //cerr<<"Drawing line!"<<endl;
            new_point = false;
            image_painter.drawLine(point2, point1);
            point2.setX(point1.x());
            point2.setY(point1.y());
        }
    }

    point1.setX(image.width() / 2);
    point1.setY(image.height());
    image_painter.drawLine(point2, point1);
    image_painter.end();

    for (int y = 0; y < image2->height(); y++) {
        for (int x = 0; x < image2->width(); x++) {
            QRgb pixel = image2->pixel(x, y);
            if (qRed(pixel) == 255) {
                //cerr<<"Found pixel"<<endl;
                current.push_back(x);
                break;
            }
        }
    }

    points = current;
    cerr << "Size of points list: " << current.size() << endl;
}

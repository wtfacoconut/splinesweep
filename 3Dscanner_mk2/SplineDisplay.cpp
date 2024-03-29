/*
 * File:   QDisplayWidget.cpp
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#include "SplineDisplay.h"

SplineDisplay::SplineDisplay(QWidget *parent, const char *name) {
    image_x = 0;
    image_y = 0;
    params.bottom_crop=0;
    params.top_crop=0;
    params.center_of_rotation=0.5;
    this->setFixedSize(WIDTH, HEIGHT);
}

SplineDisplay::~SplineDisplay() {
}

void SplineDisplay::setImage(QImage passed){
    image = passed;
    repaint();
}

void SplineDisplay::setParameters(Parameters passed) {
    params = passed;
    repaint();
}

void SplineDisplay::paintEvent(QPaintEvent *event) {
    QPainter widgetPainter(this);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(0, 255, 0));
    widgetPainter.setPen(pen);

    image = image.scaledToWidth(WIDTH,Qt::SmoothTransformation);
    widgetPainter.drawImage(image_x, image_y, image);
    widgetPainter.drawLine(params.center_of_rotation*WIDTH, 0, params.center_of_rotation*WIDTH, HEIGHT);
    pen.setColor(QColor(0, 0, 255));
    widgetPainter.setPen(pen);
    widgetPainter.drawLine(0, params.top_crop*HEIGHT, WIDTH, params.top_crop * HEIGHT);
    widgetPainter.drawLine(0, HEIGHT - (params.bottom_crop * HEIGHT) - 1, WIDTH, HEIGHT - (params.bottom_crop * HEIGHT) - 1);
    widgetPainter.end();
    return;
}
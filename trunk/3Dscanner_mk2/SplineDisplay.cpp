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
    this->setFixedSize(WIDTH, HEIGHT);
    center_of_rotation =0;;
}

SplineDisplay::~SplineDisplay() {
}

void SplineDisplay::setModelManager(ModelManager *passed) {
    model = passed;
}

void SplineDisplay::update(){
    image = model->getSplineImage(0);
    center_of_rotation = (float)((float)WIDTH/(float)image.width())*(float)model->getCenterOfRotation();
    repaint();
};

void SplineDisplay::paintEvent(QPaintEvent *event) {
    QPainter widgetPainter(this);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(0, 255, 0));
    widgetPainter.setPen(pen);

    image = image.scaledToWidth(WIDTH);
    widgetPainter.drawImage(image_x, image_y, image);
    widgetPainter.drawLine(center_of_rotation, 0,center_of_rotation, HEIGHT);
    widgetPainter.end();
    return;
}
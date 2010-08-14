/*
 * File:   QDisplayWidget.cpp
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#include "ImageDisplay.h"

ImageDisplay::ImageDisplay(QWidget *parent, const char *name) {
    image_x = 0;
    image_y = 0;
    this->setFixedSize(WIDTH, HEIGHT);
    center_of_rotation =0;;
}

ImageDisplay::~ImageDisplay() {
}

void ImageDisplay::setModelManager(ModelManager *passed) {
    model = passed;
}

void ImageDisplay::update(){
    image = model->getFirstImage();
    center_of_rotation = model->getCenterOfRotation();
    repaint();
};

void ImageDisplay::paintEvent(QPaintEvent *event) {
    QPainter widgetPainter(this);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(0, 255, 0));
    widgetPainter.setPen(pen);

    image = image.scaledToWidth(WIDTH);
    widgetPainter.drawImage(image_x, image_y, image);
    widgetPainter.drawLine(center_of_rotation*WIDTH, 0,center_of_rotation*WIDTH, HEIGHT);
    widgetPainter.end();
    return;
}
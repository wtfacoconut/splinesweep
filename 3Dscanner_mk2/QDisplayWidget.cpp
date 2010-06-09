/* 
 * File:   QDisplayWidget.cpp
 * Author: matt
 * 
 * Created on 20 January 2010, 11:54
 */

#include "QDisplayWidget.h"

QDisplayWidget::QDisplayWidget(QWidget *parent, const char *name) {
    image_x = 0;
    image_y = 0;
    //this->setFixedSize(WIDTH, HEIGHT);
}

QDisplayWidget::~QDisplayWidget() {
}

void QDisplayWidget::setImage(QImage passed_image) {
    image = passed_image;
    this->setFixedSize(image.width(),image.height());
    repaint();
    emit newImage(image);
    return;
}

void QDisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter widgetPainter(this);
    widgetPainter.drawImage(image_x, image_y, image);
    return;
}

void QDisplayWidget::mouseMoveEvent(QMouseEvent *event) {

    int x = event->pos().x();
    int y = event->pos().y();
    QRgb pixel = image.pixel(x, y);
    int red = qRed(pixel);
    int green = qGreen(pixel);
    int blue = qBlue(pixel);

    cerr << "Red: " << red << " Green: " << green << " Blue: " << blue << endl;




}
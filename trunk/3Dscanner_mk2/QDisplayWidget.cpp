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
    this->setFixedSize(WIDTH, HEIGHT);
    center_line = WIDTH / 2;
}

QDisplayWidget::~QDisplayWidget() {
}

void QDisplayWidget::setImage(QImage passed_image) {
    image = passed_image;

    //this->setFixedSize(image.width(),image.height());
    repaint();
    emit newImage(image);
    return;
}

void QDisplayWidget::setAlphaChannel(QImage passed_image) {
    alpha_channel = passed_image;
    for (int y = 0; y < alpha_channel.height(); y++) {
        for (int x = 0; x < alpha_channel.width(); x++) {
            QRgb pixel = alpha_channel.pixel(x, y);
            alpha_channel.setPixel(x, y, qRgb(qRed(pixel), qRed(pixel), qRed(pixel)));
        }
    }
    alpha_channel = alpha_channel.scaledToWidth(WIDTH);
}

void QDisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter widgetPainter(this);
    if (alpha_channel.width() == image.width() && alpha_channel.height() == image.height()) {
        image.setAlphaChannel(alpha_channel);
    }
    int line_x = (double) center_line / ((double)image.width() / (double) WIDTH);
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(0, 255, 0));
    widgetPainter.setPen(pen);
    
    image = image.scaledToWidth(WIDTH);
    widgetPainter.drawImage(image_x, image_y, image);
    widgetPainter.drawLine(line_x, 0, line_x, HEIGHT);
    widgetPainter.end();
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

void QDisplayWidget::setCenterOfRotation(int passed) {
    center_line = passed;
}
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
}

QDisplayWidget::~QDisplayWidget() {
}

void QDisplayWidget::setImage(QImage passed_image) {
    image = passed_image;
    image.scaledToWidth(WIDTH, Qt::SmoothTransformation);

    for (int y = 0; y < image.height(); y++) {
        double avg = 0;
        double count = 0;
        for (int x = 0; x < image.width(); x++) {
            QRgb pixel = image.pixel(x, y);
            if (qRed(pixel) > 0) {
                avg = avg + x;
                count++;
                image.setPixel(x,y,qRgb(0,0,0));
            }
        }
        avg = avg / count;
        if (avg > 0 && avg <= image.width()) {
            image.setPixel(avg, y, qRgb(255, 0, 0));
        }
    }

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
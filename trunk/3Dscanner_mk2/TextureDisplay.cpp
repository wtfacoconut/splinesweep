/* 
 * File:   QDisplayWidget.cpp
 * Author: matt
 * 
 * Created on 20 January 2010, 11:54
 */

#include "TextureDisplay.h"
#include "ImageDisplay.h"

TextureDisplay::TextureDisplay(QWidget *parent, const char *name) {
    image_x = 0;
    image_y = 0;
    this->setFixedSize(WIDTH, HEIGHT);
    center_of_rotation =0;
    top_crop =0;
    bottom_crop =0;
}

TextureDisplay::~TextureDisplay() {
}

void TextureDisplay::setModelManager(ModelManager *passed) {
    model = passed;
}

void TextureDisplay::update(){
    image = model->getFirstTexture();
    center_of_rotation = (float)((float)WIDTH/(float)image.width())*(float)model->getCenterOfRotation();
    repaint();
};

void TextureDisplay::paintEvent(QPaintEvent *event) {
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

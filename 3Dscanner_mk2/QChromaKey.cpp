/* 
 * File:   QChromaKey.cpp
 * Author: matt
 * 
 * Created on 20 March 2010, 15:49
 */

#include "QChromaKey.h"

QChromaKey::QChromaKey() {
    red_max = 255;
    red_min = 245;
    green_max = 255;
    green_min = 255;
    blue_max = 255;
    blue_min = 255;
    enable_red=true;
    enable_green = true;
    enable_blue = true;
}

QChromaKey::~QChromaKey() {
}

void QChromaKey::setImage(QImage passed_image) {
    image = passed_image;
    process();
}

void QChromaKey::process() {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QRgb pixel = image.pixel(x, y);
            int red = qRed(pixel);
            int green = qGreen(pixel);
            int blue = qBlue(pixel);
            int new_red=0;
            int new_green=0;
            int new_blue=0;

            if(red<=red_max && red>=red_min && enable_red){new_red=red;}
            if(green<=green_max && green>=green_min&& enable_green){new_green=green;}
            if(blue<=blue_max && blue>=blue_min&& enable_blue){new_blue=blue;}

            QRgb new_pixel = qRgb(new_red,new_green,new_blue);
            image.setPixel(x,y,new_pixel);
        }
    }
    emit(newImage(image));
}

void QChromaKey::setRedMax(int passed) {
    red_max = passed;
}

void QChromaKey::setRedMin(int passed) {
    red_min = passed;
}

void QChromaKey::setGreenMax(int passed) {
    green_max = passed;
}

void QChromaKey::setGreenMin(int passed) {
    green_min = passed;
}

void QChromaKey::setBlueMax(int passed) {
    blue_max = passed;
}

void QChromaKey::setBlueMin(int passed) {
    blue_min = passed;
}

void QChromaKey::setMaxColor(QRgb passed) {
    red_max = qRed(passed);
    green_max = qGreen(passed);
    blue_max = qBlue(passed);
}

void QChromaKey::setMinColor(QRgb passed) {
    red_min = qRed(passed);
    green_min = qGreen(passed);
    blue_min = qBlue(passed);
}
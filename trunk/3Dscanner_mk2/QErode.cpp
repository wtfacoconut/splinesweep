/* 
 * File:   QErode.cpp
 * Author: matt
 * 
 * Created on 20 March 2010, 16:36
 */

#include "QErode.h"

QErode::QErode() {
}

QErode::~QErode() {
}

void QErode::setImage(QImage passed_image)
{
    image = passed_image;
    process();
}

void QErode::process()
{
    IplImage *iplimage = QImage_2_IplImage(image);
    cvErode(iplimage,iplimage);
    image = IplImage_2_QImage(iplimage);
    cvReleaseImage(&iplimage);
    emit(newImage(image));
}
/* 
 * File:   QErode.cpp
 * Author: matt
 * 
 * Created on 20 March 2010, 16:36
 */

#include "QSmooth.h"

QSmooth::QSmooth() {
}

QSmooth::~QSmooth() {
}

void QSmooth::setImage(QImage passed_image)
{
    image = passed_image;
    process();
}

void QSmooth::process()
{
    IplImage *iplimage = QImage_2_IplImage(image);
    cvSmooth(iplimage,iplimage);
    image = IplImage_2_QImage(iplimage);
    cvReleaseImage(&iplimage);
    emit(newImage(image));
}
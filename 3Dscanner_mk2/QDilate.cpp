/* 
 * File:   QErode.cpp
 * Author: matt
 * 
 * Created on 20 March 2010, 16:36
 */

#include "QDilate.h"

QDilate::QDilate() {
}

QDilate::~QDilate() {
}

void QDilate::setImage(QImage passed_image)
{
    image = passed_image;
    process();
}

void QDilate::process()
{
    IplImage *iplimage = QImage_2_IplImage(image);
    cvDilate(iplimage,iplimage);
    image = IplImage_2_QImage(iplimage);
    cvReleaseImage(&iplimage);
    emit(newImage(image));
}
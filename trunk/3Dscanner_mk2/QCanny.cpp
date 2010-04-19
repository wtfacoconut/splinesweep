/* 
 * File:   QErode.cpp
 * Author: matt
 * 
 * Created on 20 March 2010, 16:36
 */

#include "QCanny.h"

QCanny::QCanny() {
    max =50;
    min=200;
}

QCanny::~QCanny() {
}

void QCanny::setImage(QImage passed_image)
{
    image = passed_image;
    process();
}

void QCanny::setVals(int passed_min, int passed_max){
    min = passed_min;
    max = passed_max;
}

void QCanny::process()
{
    IplImage *iplimage = QImage_2_IplImage(image);



    IplImage *result_image = cvCreateImage(cvGetSize(iplimage), IPL_DEPTH_8U, 1);
    cvCvtColor(iplimage, result_image, CV_BGR2GRAY);

    IplImage *temp_image = cvCreateImage(cvGetSize(iplimage), IPL_DEPTH_32F, 1);
    cvConvertScale(result_image,temp_image);

    //cvCanny(result_image, result_image,min, max);
    cvSobel(temp_image,temp_image,1,0,3);

    IplImage *temp_image2 = cvCreateImage(cvGetSize(iplimage), IPL_DEPTH_8U, 1);
    cvConvertScale(temp_image,temp_image2);
    cvCvtColor(temp_image2,iplimage, CV_GRAY2BGR);
    image = IplImage_2_QImage(iplimage);
    cvReleaseImage(&iplimage);
    cvReleaseImage(&result_image);
    cvReleaseImage(&temp_image);
    cvReleaseImage(&temp_image2);
    emit(newImage(image));
}
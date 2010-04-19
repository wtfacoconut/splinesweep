/* 
 * File:   QCamWidget.cpp
 * Author: matt
 * 
 * Created on 20 January 2010, 11:13
 */

#include <QImage>

#include "QCamObject.h"

QCamObject::QCamObject(QWidget *parent, const char *name) {
    cam_frame = new IplImage();
    temp = new IplImage();
    capture = cvCaptureFromCAM(0);
    if (!capture) {
        cerr << "Error: Cannot open webcam....Prepare for glourious segfault" << endl;
    }
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, CAM_WIDTH);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
    scale = 1;
    enabled = true;
}

QCamObject::~QCamObject() {
    cvReleaseCapture(&capture);
}

void QCamObject::getImage() {
    if (!capture) {
        cerr << "Error: Unable to capture from webcam" << endl;
        return;
    }

    if (!cvGrabFrame(capture)) {
        cerr << "Error: Unable to Capture From Webcam" << endl;
        return;
    }

    scale=1;

    temp = cvRetrieveFrame(capture);
    CvSize size = cvGetSize(temp);
    size.width = (double) size.width*scale;
    size.height = (double) size.height*scale;
    cam_frame = new IplImage();
    cam_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);
    cvResize(temp, cam_frame);
    frame = IplImage_2_QImage(cam_frame);
    if (enabled == true) {
        emit newImage(frame);
    }
    cvReleaseImage(&cam_frame);
    return;
}

void QCamObject::setEnabled(bool passed) {
    enabled = passed;
}

void QCamObject::setScale(double passed) {
    scale = passed;
}

QSize QCamObject::getImageSize() {
    QSize size(CAM_WIDTH, CAM_HEIGHT);
    return size;
}


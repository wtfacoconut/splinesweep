/* 
 * File:   QCamWidget.h
 * Author: matt
 *
 * Created on 20 January 2010, 11:13
 */

#ifndef _QCAMWIDGET_H
#define	_QCAMWIDGET_H

//Standard Includes
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cv.h>
#include <cvaux.h>
#include "common.h"
//OpenCV defines
#define CAM_WIDTH 640
#define CAM_HEIGHT 480

class QCamObject : public QObject{
    Q_OBJECT
public:
    QCamObject(QWidget *parent = 0, const char *name = 0);
    virtual ~QCamObject();
    QSize getImageSize();

public slots:
    void getImage();
    void setScale(double passed);
    void setEnabled(bool passed);

    signals:
    void newImage(QImage image);

private:
    //feilds
    CvCapture *capture;
    IplImage *cam_frame;
    IplImage *temp;
    QImage frame;
    double scale;
    bool enabled;
};

#endif	/* _QCAMWIDGET_H */


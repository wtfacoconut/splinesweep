/* 
 * File:   common.h
 * Author: matt
 *
 * Created on 11 February 2010, 10:12
 */

#ifndef _COMMON_H
#define	_COMMON_H
//Qt Includes
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QLayout>
#include <QVector>
//Opencv Incudes
#include <cv.h>
#include <cvaux.h>
#include <highgui.h>
//Standard Inculdes
#include <iostream>
#include <math.h>

#define PI 3.14159265


using namespace std;

static inline QImage IplImage_2_QImage(IplImage *passed) {
    QImage result = QImage(QSize(passed->width, passed->height), QImage::Format_RGB32);
    for (int y = 0; y < passed->height; y++) {
        for (int x = 0; x < passed->width; x++) {
            CvScalar pix = cvGet2D(passed, y, x);
            result.setPixel(x, y, qRgb(pix.val[2], pix.val[1], pix.val[0]));
        }
    }
    return result;
};

static inline IplImage* QImage_2_IplImage(QImage passed) {
    IplImage *result;
    result = new IplImage();
    result = cvCreateImage(cvSize(passed.width(), passed.height()), IPL_DEPTH_8U, 3);
    for (int y = 0; y < passed.height(); y++) {
        for (int x = 0; x < passed.width(); x++) {
            CvScalar s;
            QRgb qpix = passed.pixel(x, y);
            s.val[0] = qBlue(qpix);
            s.val[1] = qGreen(qpix);
            s.val[2] = qRed(qpix);
            cvSet2D(result, y, x, s);
        }
    }
    return result;
};

static inline double radianToDegree(double radian)
{
	double degree = 0;
	degree = radian * (180/PI);
	return degree;
}

inline static void RgbToYuv(int r, int g, int b, unsigned char &y, unsigned char &u, unsigned char &v) {
    y = ((77 * r) + (151 * g) + (28 * b)) / 256;
    u = ((-77 * r) + (-151 * g) + (228 * b)) / 512 + 128;
    v = ((178 * r) + (-151 * g) + (-28 * b)) / 512 + 128;
}

inline static void YuvToRgb(unsigned char y, unsigned char u, unsigned char v, int& r, int &g, int &b) {
    r = y + (double)(1.140*(double)v);
    g = y - (double)(0.395*(double)u) - (double)(0.581*(double)v);
    b = y + (double)(2.032*(double)u);
}

#endif	/* _COMMON_H */


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
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QVector>
#include <QList>
//Standard Inculdes
#include <iostream>
#include <math.h>

#define PI 3.14159265


using namespace std;


static inline double radianToDegree(double radian)
{
	double degree = 0;
	degree = radian * (180/PI);
	return degree;
}

#endif	/* _COMMON_H */


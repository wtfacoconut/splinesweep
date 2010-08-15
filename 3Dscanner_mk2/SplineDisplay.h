/*
 * File:   SplineDisplay.h
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#ifndef _SplineDisplay_H
#define	_SplineDisplay_H

//Standard Includes
#include "common.h"
#define WIDTH 640
#define HEIGHT 480
#define SCALE 4

class SplineDisplay : public QWidget {
    Q_OBJECT
public:
    SplineDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~SplineDisplay();
    void paintEvent(QPaintEvent *event);
public slots:
    void setParamters(Parameters passed);
signals:

private:
    QImage image;
    int image_x;
    int image_y;
    Parameters params;
};

#endif	/* _SplineDisplay_H */


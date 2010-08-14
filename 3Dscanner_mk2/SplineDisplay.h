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
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class SplineDisplay : public QWidget {
    Q_OBJECT
public:
    SplineDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~SplineDisplay();
    void paintEvent(QPaintEvent *event);
public slots:
    void update();
signals:

private:
    QImage image;
    int image_x;
    int image_y;
    double center_of_rotation;
    double top_crop;
    double bottom_crop;
};

#endif	/* _SplineDisplay_H */


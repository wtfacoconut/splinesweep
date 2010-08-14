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
#include "ModelManager.h"
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class SplineDisplay : public QWidget {
    Q_OBJECT
public:
    SplineDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~SplineDisplay();
    void paintEvent(QPaintEvent *event);
    void setModelManager(ModelManager *passed);
public slots:
    void update();
signals:

private:
    QImage image;
    int image_x;
    int image_y;
    int center_of_rotation;
    int top_crop;
    int bottom_crop;

    ModelManager *model;
};

#endif	/* _SplineDisplay_H */


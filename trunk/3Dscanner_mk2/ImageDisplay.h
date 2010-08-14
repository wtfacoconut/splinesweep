/*
 * File:   ImageDisplay.h
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#ifndef _ImageDisplay_H
#define	_ImageDisplay_H

//Standard Includes
#include "common.h"
#include "ModelManager.h"
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class ImageDisplay : public QWidget {
    Q_OBJECT
public:
    ImageDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~ImageDisplay();
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
    ModelManager *model;
};

#endif	/* _ImageDisplay_H */


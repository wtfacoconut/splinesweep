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
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class ImageDisplay : public QWidget {
    Q_OBJECT
public:
    ImageDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~ImageDisplay();
    void paintEvent(QPaintEvent *event);
    void setImage(QImage passed);
public slots:

    void setParamters(Parameters passed);
signals:

private:
    QImage image;
    int image_x;
    int image_y;
    Parameters params;
};

#endif	/* _ImageDisplay_H */


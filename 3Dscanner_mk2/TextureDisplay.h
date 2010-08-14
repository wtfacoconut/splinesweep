/*
 * File:   TextureDisplay.h
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#ifndef _TEXTUREDISPLAY_H
#define	_TEXTUREDISPLAY_H

//Standard Includes
#include "common.h"
#include "ModelManager.h"
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class TextureDisplay : public QWidget {
    Q_OBJECT
public:
    TextureDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~TextureDisplay();
    void paintEvent(QPaintEvent *event);
    void setModelManager(ModelManager *passed);
public slots:
    void update();
signals:

private:
    QImage image;
    int image_x;
    int image_y;
    double center_of_rotation;
    int top_crop;
    int bottom_crop;
    ModelManager *model;
};

#endif	/* _TEXTUREDISPLAY_H */


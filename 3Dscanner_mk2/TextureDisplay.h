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
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

class TextureDisplay : public QWidget {
    Q_OBJECT
public:
    TextureDisplay(QWidget *parent = 0, const char *name = 0);
    virtual ~TextureDisplay();
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

#endif	/* _TEXTUREDISPLAY_H */


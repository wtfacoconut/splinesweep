/* 
 * File:   GUI.h
 * Author: matt
 *
 * Created on 16 February 2010, 13:20
 */

#ifndef _GUI_H
#define	_GUI_H

#include "common.h"
#include "ModelGenerator.h"
#include "SplineGenerator.h"
#include "ModelManager.h"
#include "TextureDisplay.h"
#include "SplineDisplay.h"
#include "ImageDisplay.h"

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI(QWidget *parent = 0, const char *name = 0);
    virtual ~GUI();
public slots:
    void generateModel();
private:
    QTabWidget *optiontabs;
    QGridLayout *layout;
    ImageDisplay *image_display;
    TextureDisplay *texture_display;
    SplineDisplay *spline_display;
    SplineGenerator *splinegen;
    ModelGenerator *modelgen;
    ModelManager *modelmanager;
};

#endif	/* _GUI_H */


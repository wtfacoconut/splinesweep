/* 
 * File:   GUI.h
 * Author: matt
 *
 * Created on 16 February 2010, 13:20
 */

#ifndef _GUI_H
#define	_GUI_H

#include "common.h"
#include "ImageLoader.h"
#include "ModelGen.h"
#include "QDisplayWidget.h"
#include "SplineGenerator.h"

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI(QWidget *parent = 0, const char *name = 0);
    virtual ~GUI();
public slots:
    void generateModel(bool passed);
private:
    QGridLayout *layout;
    ImageLoader *loader;
    QDisplayWidget *spline_display;
    QDisplayWidget *texture_display;
    SplineGenerator *splinegen;
    ModelGen *modelgen;
};

#endif	/* _GUI_H */


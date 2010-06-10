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
#include "ModelGenerator.h"
#include "QDisplayWidget.h"
#include "SplineGenerator.h"


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
    ImageLoader *loader;
    QDisplayWidget *spline_display;
    QDisplayWidget *texture_display;
    SplineGenerator *splinegen;
    ModelGenerator *modelgen;
};

#endif	/* _GUI_H */


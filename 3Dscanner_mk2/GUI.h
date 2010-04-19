/* 
 * File:   GUI.h
 * Author: matt
 *
 * Created on 16 February 2010, 13:20
 */

#ifndef _GUI_H
#define	_GUI_H
#include <QWidget>
#include <QLayout>
#include <QTimer>
#include "ImageLoader.h"
#include "ModelGen.h"
#include "QCamObject.h"
#include "QDisplayWidget.h"
#include "QChromaKey.h"
#include "QDilate.h"
#include "QErode.h"
#include "QCanny.h"
#include "QSmooth.h"

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI(QWidget *parent = 0, const char *name = 0);
    virtual ~GUI();
public slots:
    void generateModel(bool passed);
private:
    QLayout *layout;
    QCamObject *camobject;
    ImageLoader *loader;
    QDisplayWidget *displaywidget;
    ModelGen *modelgen;
    QChromaKey *chromakey1;
    QChromaKey *chromakey2;
    QErode *erode;
    QDilate *dilate;
    QCanny *canny;
    QSmooth *smooth;
    QTimer *timer;
};

#endif	/* _GUI_H */


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
#include "QDisplayWidget.h"

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI(QWidget *parent = 0, const char *name = 0);
    virtual ~GUI();
public slots:
    void generateModel(bool passed);
private:
    QLayout *layout;
    ImageLoader *loader;
    QDisplayWidget *displaywidget;
    ModelGen *modelgen;
};

#endif	/* _GUI_H */


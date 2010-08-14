/* 
 * File:   GUI.cpp
 * Author: matt
 * 
 * Created on 16 February 2010, 13:20
 */

#include "GUI.h"


GUI::GUI(QWidget *parent, const char *name) {

    layout = new QGridLayout(this);
    layout->setMargin(1);
    
    optiontabs= new QTabWidget();

    modelmanager = new ModelManager();
    image_display = new ImageDisplay(this,0);
    texture_display = new TextureDisplay(this, 0);
    spline_display = new SplineDisplay(this,0);

    image_display->setModelManager(modelmanager);
    texture_display->setModelManager(modelmanager);
    spline_display->setModelManager(modelmanager);
    connect(modelmanager,SIGNAL(newModel()),image_display,SLOT(update()));
    connect(modelmanager,SIGNAL(newModel()),texture_display,SLOT(update()));
    connect(modelmanager,SIGNAL(newModel()),spline_display,SLOT(update()));
    
    modelgen = new ModelGenerator();
    splinegen = new SplineGenerator();

    optiontabs->addTab(modelmanager,"Image Loading");
    optiontabs->addTab(splinegen,"Spline Generation");
    optiontabs->addTab(modelgen,"Model Building");

    layout->addWidget(image_display,0,0);
    layout->addWidget(texture_display,0,1);
    layout->addWidget(spline_display,0,2);
    layout->addWidget(optiontabs,1,0,1,3);
}



GUI::~GUI() {
}

void GUI::generateModel()
{
    /*int num_images = loader->getNumImages();
    connect(displaywidget,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    connect(loader,SIGNAL(newTexture(QImage)),modelgen,SLOT(setTexture(QImage)));
    for(int loop =0 ; loop< num_images; loop++)
    {
        loader->nextImage(true);
    }
    disconnect(displaywidget,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    disconnect(loader,SIGNAL(newTexture(QImage)),modelgen,SLOT(setTexture(QImage)));*/
}

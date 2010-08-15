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
    image_manager = new ImageManager();
    model_manager = new ModelManager();
    model_manager->setImageManager(image_manager);
    //optiontabs= new QTabWidget();

    //optiontabs->addTab(modelmanager,"Image Loading");
    //optiontabs->addTab(splinegen,"Spline Generation");
    //optiontabs->addTab(modelgen,"Model Building");

    layout->addWidget(image_manager,0,0);
    layout->addWidget(model_manager,0,1);

    connect(image_manager, SIGNAL(selectedImage(int)), model_manager,SLOT(updateSplineImage(int)));
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

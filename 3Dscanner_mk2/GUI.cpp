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


    //camobject = new QCamObject(this, 0);
    loader = new ImageLoader(this,0);
    spline_display = new QDisplayWidget(this, 0);
    texture_display = new QDisplayWidget(this, 0);

    modelgen = new ModelGenerator();
    splinegen = new SplineGenerator();

    optiontabs->addTab(loader,"Image Loading");
    optiontabs->addTab(splinegen,"Spline Generation");
    optiontabs->addTab(modelgen,"Model Building");

    layout->addWidget(spline_display,0,0);
    layout->addWidget(texture_display,0,1);    
    layout->addWidget(optiontabs,1,0,1,2);

    /*layout->addWidget(loader,1,0,1,2);


    layout->addWidget(makemodel,2,0,1,2);
    layout->addWidget(splinegen,3,0,1,2);*/
    connect(loader,SIGNAL(newNumImages(int)),modelgen, SLOT(setNumImages(int)));
    connect(loader,SIGNAL( newEnableTexture(bool)),modelgen,SLOT(setEnableTexture(bool)));
    connect(modelgen,SIGNAL(newCenterOfRotation(int)), spline_display, SLOT(setCenterOfRotation(int)));
    connect(modelgen,SIGNAL(newCenterOfRotation(int)), texture_display, SLOT(setCenterOfRotation(int)));

    connect(loader,SIGNAL(newImage(QImage)),splinegen,SLOT(setImage(QImage)));
    connect(splinegen,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    connect(loader,SIGNAL(newTexture(QImage)),modelgen,SLOT(setTexture(QImage)));
    connect(modelgen,SIGNAL(newTexture(QImage)), texture_display, SLOT(setImage(QImage)));
    connect(modelgen,SIGNAL(newImage(QImage)),spline_display, SLOT(setImage(QImage)));
    
    connect(modelgen,SIGNAL(requestImage(int)), loader,SLOT(getImage(int)));
    connect(modelgen,SIGNAL(requestTexture(int)),loader,SLOT(getTexture(int)));


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

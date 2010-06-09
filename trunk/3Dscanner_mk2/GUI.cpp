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
    QPushButton *makemodel = new QPushButton("Generate Model");

    //camobject = new QCamObject(this, 0);
    loader = new ImageLoader(this,0);
    displaywidget = new QDisplayWidget(this, 0);
    modelgen = new ModelGen();
   

    layout->addWidget(displaywidget);
    layout->addWidget(loader);
    layout->addWidget(makemodel);

    connect(makemodel,SIGNAL(clicked(bool)),this,SLOT(generateModel(bool)));
    connect(loader,SIGNAL(newNumImages(int)),modelgen, SLOT(setNumImages(int)));
    connect(loader,SIGNAL(newImage(QImage)),displaywidget,SLOT(setImage(QImage)));
}

GUI::~GUI() {
}

void GUI::generateModel(bool passed)
{
    int num_images = loader->getNumImages();
    connect(displaywidget,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    connect(loader,SIGNAL(newTexture(QImage)),modelgen,SLOT(setTexture(QImage)));
    for(int loop =0 ; loop< num_images; loop++)
    {
        loader->nextImage(true);
    }
    disconnect(displaywidget,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    disconnect(loader,SIGNAL(newTexture(QImage)),modelgen,SLOT(setTexture(QImage)));
}

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
    
    chromakey1 = new QChromaKey();
    chromakey1->setRedMax(255);
    chromakey1->setRedMin(170);
    chromakey1->setGreenMax(255);
    chromakey1->setGreenMin(170);
    chromakey1->setBlueMax(255);
    chromakey1->setBlueMin(170);

    chromakey2 = new QChromaKey();
    chromakey2->setRedMax(256);
    chromakey2->setRedMin(10);
    chromakey2->setGreenMax(255);
    chromakey2->setGreenMin(10);
    chromakey2->setBlueMax(256);
    chromakey2->setBlueMin(10);
    erode = new QErode();
    dilate = new QDilate();
    canny = new QCanny();
    smooth = new QSmooth();

    timer = new QTimer(this);

    layout->addWidget(displaywidget);
    layout->addWidget(loader);
    layout->addWidget(makemodel);

    connect(makemodel,SIGNAL(clicked(bool)),this,SLOT(generateModel(bool)));

    connect(loader,SIGNAL(newNumImages(int)),modelgen, SLOT(setNumImages(int)));
    
    //connect(timer, SIGNAL(timeout()), camobject, SLOT(getImage()));

    //connect(camobject,SIGNAL(newImage(QImage)),chromakey1,SLOT(setImage(QImage)));
    //connect(camobject,SIGNAL(newImage(QImage)),canny,SLOT(setImage(QImage)));
    connect(loader,SIGNAL(newImage(QImage)),canny,SLOT(setImage(QImage)));
    ///connect (chromakey1,SIGNAL(newImage(QImage)),canny,SLOT(setImage(QImage)));
    //connect (erode,SIGNAL(newImage(QImage)),smooth,SLOT(setImage(QImage)));
    //connect(canny,SIGNAL(newImage(QImage)),smooth,SLOT(setImage(QImage)));
    canny->setVals(50,250);
    connect(canny,SIGNAL(newImage(QImage)),chromakey1,SLOT(setImage(QImage)));
    //connect(erode,SIGNAL(newImage(QImage)),displaywidget,SLOT(setImage(QImage)));
    //connect(erode,SIGNAL(newImage(QImage)),chromakey2,SLOT(setImage(QImage)));
    connect(chromakey1,SIGNAL(newImage(QImage)),displaywidget,SLOT(setImage(QImage)));
    //connect(displaywidget,SIGNAL(newImage(QImage)),modelgen,SLOT(setImage(QImage)));
    timer->start(50);
}

GUI::~GUI() {
    delete camobject;
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

/* 
 * File:   ModelManager.cpp
 * Author: matt
 * 
 * Created on 14 August 2010, 18:34
 */

#include "ModelManager.h"

ModelManager::ModelManager() {
    splines_ready = false;
    spline_display = new SplineDisplay();
    spline_generator = new SplineGenerator();

    QPushButton *gen_splines = new QPushButton("Generate Splines");

    layout = new QGridLayout(this);
    layout->addWidget(spline_display,0,0);
    options_tabs= new QTabWidget();
    options_tabs->addTab(spline_generator,"Spline Generator Settings");
    layout->addWidget(options_tabs);
    layout->addWidget(gen_splines);

    connect(gen_splines,SIGNAL(clicked(bool)),this,SLOT(generateSplines(bool)));

}

ModelManager::~ModelManager() {
}

void ModelManager::setImageManager(ImageManager *passed) {
    image_manager = passed;
}

void ModelManager::generateSplines(bool passed) {

    for (int loop = 0; loop < image_manager->getNumImages(); loop++) {
        splines.push_back(spline_generator->process(image_manager->getImage(loop)));
    }
    cerr<<"Generated "<<image_manager->getNumImages()<<" splines"<<endl;
    splines_ready = true;
    //updateSplineImage(0);
}


void ModelManager::updateSplineImage(int index){
    cerr<<"Setting spline image to: "<<index<<endl;
    spline_display->setImage(getSplineImage(index));
}

QImage ModelManager::getSplineImage(int location) {
    if (location >= splines.size()) {
        cerr << "Spline: " << location << " does not exist yet" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    }
    if (splines[location].size() == 0) {
        cerr << "Spline: " << location << " exists but is empty" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    }
    QImage image;
    /*if (image.load(image_locations[location].toStdString().c_str()) == false) {
        cerr << "Spline " << location << " exists, but does not have an associated image" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    }*/
    /*if (splines[location].size() != image.height()) {
        cerr << "Spline " << location << " exists, but is not the right size" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    };*/

    QImage spline_image = QImage(800, splines[location].size(), QImage::Format_RGB32);
    for (int loop = splines[location].size()-1; loop >=0 ; loop--) {
        QRgb pixel;
        pixel = qRgb(255, 0, 0);
        spline_image.setPixel(splines[location][loop], loop, pixel);

    }
    return spline_image;
}
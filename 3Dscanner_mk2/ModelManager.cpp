/* 
 * File:   ModelManager.cpp
 * Author: matt
 * 
 * Created on 14 August 2010, 18:34
 */

#include "ModelManager.h"

ModelManager::ModelManager() {
    params.bottom_crop=0;
    params.top_crop =0;
    params.center_of_rotation=0.5;
    splines_ready = false;
    spline_display = new SplineDisplay();
    spline_generator = new SplineGenerator();

    QPushButton *gen_splines = new QPushButton("Generate Splines");
    QPushButton *gen_model = new QPushButton("Generate Model");

    layout = new QGridLayout(this);
    layout->addWidget(spline_display, 0, 0,1,2);
    options_tabs = new QTabWidget();
    options_tabs->addTab(spline_generator, "Spline Generator Settings");
    //initCropControls();
    layout->addWidget(options_tabs,1,0,1,2);
    //layout->addWidget(spline_generator);


    QWidget *crop_controls = new QWidget();
    QDoubleSpinBox *topcrop_spinbox = new QDoubleSpinBox();
    topcrop_spinbox->setRange(0, 0.5);
    topcrop_spinbox->setSingleStep(0.005);
    QDoubleSpinBox *bottomcrop_spinbox = new QDoubleSpinBox();
    bottomcrop_spinbox->setRange(0, 0.5);
    bottomcrop_spinbox->setSingleStep(0.005);
    QDoubleSpinBox *center_spinbox = new QDoubleSpinBox();
    center_spinbox->setRange(0, 1);
    center_spinbox->setSingleStep(0.005);
    center_spinbox->setValue(0.5);

    QGridLayout *crop_layout = new QGridLayout(crop_controls);
    crop_layout->addWidget(new QLabel("Top Crop"), 0, 0);
    crop_layout->addWidget(topcrop_spinbox, 0, 1);
    crop_layout->addWidget(new QLabel("Bottom Crop"), 0, 2);
    crop_layout->addWidget(bottomcrop_spinbox, 0, 3);
    crop_layout->addWidget(new QLabel("Center of Rotation"), 1, 0);
    crop_layout->addWidget(center_spinbox, 1, 1);
    options_tabs->addTab(crop_controls, "Crop Controls");

    layout->addWidget(gen_splines,2,0);
    layout->addWidget(gen_model,2,1);
    connect(gen_splines, SIGNAL(clicked(bool)), this, SLOT(generateSplines(bool)));
    connect(topcrop_spinbox,SIGNAL(valueChanged(double)),this,SLOT(newTopCrop(double)));
    connect(bottomcrop_spinbox,SIGNAL(valueChanged(double)),this,SLOT(newBottomCrop(double)));
    connect(center_spinbox,SIGNAL(valueChanged(double)),this,SLOT(newCenter(double)));
    connect(this, SIGNAL(newParameters(Parameters)),spline_display,SLOT(setParameters(Parameters)));


}

ModelManager::~ModelManager() {
}

void ModelManager::initCropControls() {
    //crop_layout = new QGridLayout();
    //options_tabs->addTab(crop_layout,"Crop Controls");
}

void ModelManager::setImageManager(ImageManager *passed) {
    image_manager = passed;
}

void ModelManager::generateSplines(bool passed) {

    for (int loop = 0; loop < image_manager->getNumImages(); loop++) {
        splines.push_back(spline_generator->process(image_manager->getImage(loop)));
    }
    cerr << "Generated " << image_manager->getNumImages() << " splines" << endl;
    splines_ready = true;
    width = image_manager->getFirstImage().size().width(); //Get the width of the images so the spline image is genreated properly.
    updateSplineImage(0);
}

void ModelManager::updateSplineImage(int index) {
    cerr << "Setting spline image to: " << index << endl;
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

    QImage spline_image = QImage(width, splines[location].size(), QImage::Format_RGB32);
    for (int loop = splines[location].size() - 1; loop >= 0; loop--) {
        QRgb pixel;
        pixel = qRgb(255, 0, 0);
        spline_image.setPixel(splines[location][loop], loop, pixel);

    }
    return spline_image;
}

void ModelManager::newTopCrop(double passed) {
    params.top_crop = passed;
    emit newParameters(params);
}

void ModelManager::newBottomCrop(double passed) {
    params.bottom_crop = passed;
    emit newParameters(params);
}

void ModelManager::newCenter(double passed) {
    params.center_of_rotation = passed;
    emit newParameters(params);
}

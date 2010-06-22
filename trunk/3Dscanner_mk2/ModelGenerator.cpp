/* 
 * File:   ModelGenerator.cpp
 * Author: matt
 * 
 * Created on 10 June 2010, 18:15
 */

#include "ModelGenerator.h"

ModelGenerator::ModelGenerator() {
    center_of_rotation = 400;
    top_crop = 0;
    bottom_crop = 0;
    enabled = false;
    enable_texture = false;

    layout = new QGridLayout(this);
    generate_button = new QPushButton("Generate Model");
    top_crop_spinbox = new QSpinBox();
    bottom_crop_spinbox = new QSpinBox();
    center_spinbox = new QSpinBox();

    top_crop_spinbox->setRange(0, 800);
    bottom_crop_spinbox->setRange(0, 800);
    center_spinbox->setRange(0, 800);

    top_crop_spinbox->setValue(top_crop);
    bottom_crop_spinbox->setValue(bottom_crop);
    center_spinbox->setValue(center_of_rotation);


    layout->addWidget(generate_button, 0, 0, 1, 4);
    layout->addWidget(new QLabel("Top crop "), 1, 0);
    layout->addWidget(top_crop_spinbox, 1, 1);
    layout->addWidget(new QLabel("Bottom crop "), 1, 2);
    layout->addWidget(bottom_crop_spinbox, 1, 3);
    layout->addWidget(new QLabel("Center of rotation"), 2, 0);
    layout->addWidget(center_spinbox, 2, 1);

    connect(top_crop_spinbox, SIGNAL(valueChanged(int)), this, SLOT(setTopCrop(int)));
    connect(bottom_crop_spinbox, SIGNAL(valueChanged(int)), this, SLOT(setBottomCrop(int)));
    connect(center_spinbox, SIGNAL(valueChanged(int)), this, SLOT(setCenterOfRotation(int)));
}

ModelGenerator::~ModelGenerator() {
}

void ModelGenerator::setImage(QImage passed) {
    current_spline = passed;

    if (enabled == true) {
        addSpline();
        if (depth_map.size() == num_images)process();
    }
    emit newCenterOfRotation(center_of_rotation);
    emit newImage(crop(current_spline));
}

void ModelGenerator::setTexture(QImage passed) {
    current_texture = passed;
    if (enabled == true) {

    }
    emit newCenterOfRotation(center_of_rotation);
    emit newTexture(crop(current_texture));
}

void ModelGenerator::addSpline() {
    for (int y = 0; y < current_spline.height(); y++) {
        for (int x = 0; x < current_spline.width(); x--) {

        }
    }



}

void ModelGenerator::setEnableTexture(bool passed) {
    if (passed)cerr << "Textures enabled and loaded" << endl;
    if (!passed)cerr << "Texture disabled" << endl;
    enable_texture = passed;
}

void ModelGenerator::generate(bool passed) {
    enabled = true;

    for (int loop = 0; loop < num_images; loop++) {
        emit requestImage(loop);
    }

}

void ModelGenerator::setNumImages(int passed) {
    num_images = passed;
}

void ModelGenerator::setTopCrop(int passed) {
    top_crop = passed;
    cerr << "Top crop set to: " << top_crop << endl;
}

void ModelGenerator::setBottomCrop(int passed) {
    bottom_crop = passed;
    cerr << "Bottom crop set to: " << bottom_crop << endl;
}

void ModelGenerator::setCenterOfRotation(int passed) {
    center_of_rotation = passed;
    emit newCenterOfRotation(center_of_rotation);
    emit newTexture(crop(current_texture));
    emit newImage(crop(current_spline));
    cerr << "Center of rotation set to: " << center_of_rotation << endl;
}

void ModelGenerator::process() {

    if (enable_texture == true) {
        //load the relevant texture points
    }
}

QImage ModelGenerator::crop(QImage passed) {
    QImage newimage = passed.copy(0, top_crop, passed.width(), passed.height() - top_crop - bottom_crop);
    return newimage;
}
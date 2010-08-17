/* 
 * File:   ModelGenerator.cpp
 * Author: matt
 * 
 * Created on 10 June 2010, 18:15
 */

#include "ModelGenerator.h"
#include <QDoubleSpinBox>

ModelGenerator::ModelGenerator() {
    layout = new QGridLayout(this);
    QDoubleSpinBox *angle_spinbox = new QDoubleSpinBox();
    angle_spinbox->setRange(0, 180);
    angle_spinbox->setSingleStep(0.5);
    angle_spinbox->setValue(45);
    layout->addWidget(new QLabel("Angle of Laser"), 0, 0);
    layout->addWidget(angle_spinbox, 0, 1);
    connect(angle_spinbox, SIGNAL(valueChanged(double)), this, SLOT(setLaserAngle(double)));
}

ModelGenerator::~ModelGenerator() {
}

void ModelGenerator::setParameters(Parameters passed) {
    params = passed;
}

void ModelGenerator::setImageManager(ImageManager *passed) {
    image_manager = passed;
}

void ModelGenerator::setSplines(QVector< QVector<int> > passed) {
    splines = passed;
}

void ModelGenerator::setLaserAngle(double passed) {
    laserAngle = passed;
}

void ModelGenerator::generateModel(QVector< QVector<int> > passed) {
    splines = passed;
    int number_of_rotations = image_manager->number_of_images;
    int image_width = image_manager->getFirstImage().width();
    int image_height = image_manager->getFirstImage().height();

    //Generate the texture
    texture = QImage(number_of_rotations, image_width, QImage::Format_RGB32);
    for (int x = 0; x < number_of_rotations; x++) {
        QImage tex = image_manager->getTexture(x);
        tex = tex.scaled(image_width,image_height);
        for (int y = 0; y = image_height; y++) {
            texture.setPixel(x,y,tex.pixel(splines[x][y],y));
        }
    }

    
}
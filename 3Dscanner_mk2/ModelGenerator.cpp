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
    angle_spinbox->setRange(0,180);
    angle_spinbox->setSingleStep(0.5);
    angle_spinbox->setValue(45);
    layout->addWidget(new QLabel("Angle of Laser"),0,0);
    layout->addWidget(angle_spinbox,0,1);
    connect(angle_spinbox, SIGNAL(valueChanged(double)),this,SLOT(setLaserAngle(double)));   
}

ModelGenerator::~ModelGenerator() {
}

void ModelGenerator::setParameters(Parameters passed) {
    params = passed;
}

void ModelGenerator::setImageManager(ImageManager *passed) {
    image_manager = passed;
}

void ModelGenerator::setSplines(QVector< QVector<int> > passed){
    splines = passed;
}

void ModelGenerator::setLaserAngle(double passed){
    laserAngle = passed;
}
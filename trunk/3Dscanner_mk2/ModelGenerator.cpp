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

void ModelGenerator::generateModel(QVector< QVector<int> > passed, QString passed_name) {
    splines = passed;
    filename = passed_name;
    int number_of_rotations = image_manager->number_of_images;
    int image_width = image_manager->getFirstImage().width();
    int image_height = image_manager->getFirstImage().height();

    //Generate the texture
    texture = QImage(number_of_rotations, image_width, QImage::Format_RGB32);
    for (int x = 0; x < number_of_rotations; x++) {
        QImage tex = image_manager->getTexture(x);
        tex = tex.scaled(image_width, image_height);
        for (int y = 0; y < image_height; y++) {
            texture.setPixel(x, y, tex.pixel(splines[x][y], y));
        }
    }


    //THINGS TO FIX!!!!
    //add cropping of top and bottom
    //add setting center of rotation

    for (int x = 0; x < number_of_rotations; x++) {
        QVector<point> spl;
        mesh.push_back(spl);
        double rotation = (360 / (double) number_of_rotations) * x;
        for (int y = 0; y < image_height; y++) {
            point po;
            po.x = (double) cos((double) (rotation / 57.29578))* ((image_width / 2) - splines[x][y]);
            po.y = y;
            po.z = (double) sin((double) (rotation / 57.29578))* ((image_width / 2) - splines[x][y]);
            //cerr << "point @ " << po.x << " " << po.y << " " << po.z << endl;
            mesh[x].push_back(po);
        }
    }

    QFile test;
    filename.append(".obj");
    test.setFileName(filename);
    test.open(QIODevice::WriteOnly);
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < number_of_rotations; x++) {

            QString x_val = QString::number(mesh[x][y].x);
            QString y_val = QString::number(mesh[x][y].y);
            QString z_val = QString::number(mesh[x][y].z);

            QString line;
            line.append("v ");
            line.append(x_val);
            line.append(" ");
            line.append(y_val);
            line.append(" ");
            line.append(z_val);
            line.append("\n");
            cout<<line.toStdString().c_str();
            test.write(line.toStdString().c_str());
        }
    }
    test.close();

}
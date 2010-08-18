/* 
 * File:   ModelGenerator.cpp
 * Author: matt
 * 
 * Created on 10 June 2010, 18:15
 */

#include "ModelGenerator.h"
#include <QDoubleSpinBox>
#include <QTextStream>

ModelGenerator::ModelGenerator() {
    layout = new QGridLayout(this);
    QDoubleSpinBox *angle_spinbox = new QDoubleSpinBox();
    angle_spinbox->setRange(0, 180);
    angle_spinbox->setSingleStep(0.5);
    angle_spinbox->setValue(35);
    layout->addWidget(new QLabel("Angle of Laser"), 0, 0);
    layout->addWidget(angle_spinbox, 0, 1);
    connect(angle_spinbox, SIGNAL(valueChanged(double)), this, SLOT(setLaserAngle(double)));
    laserAngle = angle_spinbox->value();
    params.center_of_rotation = 0.5;
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
    int image_width = image_manager->getFirstImage().width(); // splines.size()
    int image_height = image_manager->getFirstImage().height(); //= splines.front().size();

    //Generate the texture
    texture = QImage(number_of_rotations * 5, image_height, QImage::Format_RGB32);
    for (int x = 0; x < number_of_rotations; x++) {
        QImage tex = image_manager->getTexture(x);
        tex = tex.scaled(image_width, image_height);
        for (int y = 0; y < image_height; y++) {
            if ((x * 5) - 2 >= 0)texture.setPixel((x * 5) - 2, y, tex.pixel(splines[x][y] - 1, y));
            if ((x * 5) - 1 >= 0)texture.setPixel((x * 5) - 1, y, tex.pixel(splines[x][y] - 1, y));
            texture.setPixel((x * 5), y, tex.pixel(splines[x][y], y));
            texture.setPixel((x * 5) + 1, y, tex.pixel(splines[x][y] + 1, y));
            texture.setPixel((x * 5) + 2, y, tex.pixel(splines[x][y] + 2, y));
        }
    }

    QString texture_file = filename;
    texture_file.append(".png");
    texture.save(texture_file);
    QString mat_file = filename;
    mat_file.append(".mtl");

    //THINGS TO FIX!!!!
    //add cropping of top and bottom
    //add setting center of rotation

    double spline_mult = cos((double) (90 - (double) laserAngle) / 57.29578); //Account for the angle of the laser
    //spline_mult = 0.3;
    for (int x = 0; x < number_of_rotations; x++) {
        QVector<point> spl;
        mesh.push_back(spl);
        double rotation = (360 / (double) number_of_rotations) * (double) x;
        for (int y = 0; y < image_height; y++) {
            double spline_point = ((double) (((double) ((double) image_width * params.center_of_rotation)-(double) splines[x][y])) / spline_mult);
            point po;
            po.x = (double) cos((double) (rotation / 57.29578)) * spline_point;
            po.y = y;
            po.z = (double) sin((double) (rotation / 57.29578)) * spline_point;
            //cerr << "point @ " << po.x << " " << po.y << " " << po.z << endl;
            mesh[x].push_back(po);
        }
    }

    QFile file;
    QString object_file = filename;
    object_file.append(".obj");
    file.setFileName(object_file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    for (int y = splines[0].size()-1; y >=0 ; y--) {
        for (int x = 0; x <splines.size() ; x++) {
            QString line = QString("vt ");
            line.append(QString(" ").append(QString::number((double) (1 / (double)splines.size())*x )));
            line.append(QString(" ").append(QString::number((double) (1 / (double) splines[0].size())*y)));
            out<<line.toStdString().c_str()<<endl;
        }
    }
    out << "mtllib " << mat_file.toStdString().c_str()<< endl;
    out << "usemtl Textured" << endl;

    int count = 1;
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
            out << line.toStdString().c_str();
            count++;
        }
    }



    //cout<<"f v1 v2 v101 v102"<<endl;
    //cout<<"f v2 v3 v101 v102"<<endl;
    //cout<<"f v3 v4 v103 v104"<<endl;

    count = 1;
    for (int y = 0; y < splines[0].size() - 1; y++) {
        for (int x = 0; x < splines.size() - 1; x++) {
            QString line;
            int x_val = count;

            QString tl = QString(" ").append(QString::number(x_val));
            QString tr = QString(" ").append(QString::number(x_val + 1));
            QString bl = QString(" ").append(QString::number(x_val + splines.size()));
            QString br = QString(" ").append(QString::number(x_val + splines.size() + 1));

            line.append("f ");
            line.append(tl);
            line.append("/");
            line.append(QString::number(count));
            line.append(tr);
            line.append("/");
            line.append(QString::number(count + 1));
            line.append(br);
            line.append("/");
            line.append(QString::number(count + splines.size() + 1));
            line.append(bl);
            line.append("/");
            line.append(QString::number(count + splines.size()));
            line.append("\n");
            out << line.toStdString().c_str();
            count++;
        }
    }



    file.close();


    QFile mtl;
    mtl.setFileName(mat_file);
    mtl.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out2(&mtl);
    QString mat_file_line = QString("newmtl Textured \nKa 1.000 1.000 1.000\nKd 1.000 1.000 1.000\nKs 0.000 0.000 0.000\nd 1.0\nTr 1.0\nillum 2\nmap_Ka ");

    mat_file_line.append(texture_file);
    mat_file_line.append("\nmap_Kd ");
    mat_file_line.append(texture_file);
    out2 << mat_file_line.toStdString().c_str();

    mtl.close();

}


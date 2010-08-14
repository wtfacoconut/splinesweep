/* 
 * File:   ModelManager.cpp
 * Author: matt
 * 
 * Created on 13 August 2010, 19:01
 */

#include "ModelManager.h"

ModelManager::ModelManager() {
    top_crop = 0;
    bottom_crop = 0;
    center_of_rotation = 0;
    textures_ready = false;
    images_ready = false;
    splines_ready = false;

    layout = new QGridLayout(this);
    file_opener = new QFileDialog();
    file_opener->setNameFilter(tr("Images (*.png *.bmp *.jpg *.jpeg)"));
    file_opener->setFileMode(QFileDialog::ExistingFiles);
    file_opener->setVisible(false);
    tex_opener = new QFileDialog();
    tex_opener->setNameFilter(tr("Images (*.png *.bmp *.jpg *.jpeg)"));
    tex_opener->setFileMode(QFileDialog::ExistingFiles);
    tex_opener->setVisible(false);
    QPushButton *load_button = new QPushButton("Load Images");
    QPushButton *load_textures = new QPushButton("Load Textures");
    layout->addWidget(load_button, 0, 0);
    layout->addWidget(load_textures, 0, 1);


    connect(load_button, SIGNAL(clicked(bool)), this, SLOT(displayLoadDialog(bool)));
    connect(load_textures, SIGNAL(clicked(bool)), this, SLOT(displayTexDialog(bool)));
    connect(file_opener, SIGNAL(filesSelected(const QStringList &)), this, SLOT(loadImages(const QStringList &)));
    connect(tex_opener, SIGNAL(filesSelected(const QStringList &)), this, SLOT(loadTextures(const QStringList &)));
}

ModelManager::~ModelManager() {
}

QImage ModelManager::getImage(int location) {
    QImage image;
    if (image_locations.size() == 0) {
        image = QImage(800, 600, QImage::Format_RGB32);
        return image;
    }
    if (image.load(image_locations.at(location)))return image;
    image = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load image" << image_locations.at(location).toStdString().c_str() << endl;
    return image;

}

QImage ModelManager::getFirstImage() {
    QImage image;
    if (image_locations.size() == 0) {
        image = QImage(800, 600, QImage::Format_RGB32);
        return image;
    }
    if (image.load(image_locations.first()))return image;
    image = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load image" << image_locations.first().toStdString().c_str() << endl;
    return image;
}

QImage ModelManager::getLastImage() {
    QImage image;
    if (image_locations.size() == 0) {
        image = QImage(800, 600, QImage::Format_RGB32);
        return image;
    }
    if (image.load(image_locations.last()))return image;
    image = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load image" << image_locations.last().toStdString().c_str() << endl;
    return image;
}

QImage ModelManager::getTexture(int location) {
    QImage texture;
    if (texture_locations.size() == 0) {
        texture = QImage(800, 600, QImage::Format_RGB32);
        cerr << "Texture does not exist" << endl;
        return texture;
    }
    if (texture.load(texture_locations.at(location)))return texture;
    texture = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load texture" << texture_locations.at(location).toStdString().c_str() << endl;
    return texture;
}

QImage ModelManager::getFirstTexture() {
    QImage texture;
    if (texture_locations.size() == 0) {
        texture = QImage(800, 600, QImage::Format_RGB32);
        return texture;
    }
    if (texture.load(texture_locations.first()))return texture;
    texture = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load texture" << texture_locations.first().toStdString().c_str() << endl;
    return texture;
}

QImage ModelManager::getLastTexture() {
    QImage texture;
    if (texture_locations.size() == 0) {
        texture = QImage(800, 600, QImage::Format_RGB32);
        return texture;
    }
    if (texture.load(texture_locations.last()))return texture;
    texture = QImage(800, 600, QImage::Format_RGB32);
    cerr << "Unable to load texture" << texture_locations.last().toStdString().c_str() << endl;
    return texture;
}

QVector<QVector <int> > ModelManager::getSplines() {
    return splines;
}

QVector<int> ModelManager::getSpline(int x) {
    if (x > splines.size()) {
        QVector<int> blank;
        return blank;
    }

    return splines[x];
}

int ModelManager::getPoint(int x, int y) {
    if (x > splines.size()) return 0;
    if (y > splines[x].size()) return 0;
    return splines[x][y];
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
    if (image.load(image_locations[location].toStdString().c_str()) == false) {
        cerr << "Spline " << location << " exists, but does not have an associated image" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    }
    if (splines[location].size() != image.height()) {
        cerr << "Spline " << location << " exists, but is not the right size" << endl;
        return QImage(800, 600, QImage::Format_RGB32);
    };

    QImage spline_image = QImage(image.width(), image.height(), QImage::Format_RGB32);
    for (int loop = 0; loop < splines[location].size(); loop++) {
        QRgb pixel;
        pixel = qRgb(255, 0, 0);
        spline_image.setPixel(splines[location][loop], loop, pixel);
    }
    return spline_image;
}

void ModelManager::setImageLocations(QStringList passed) {
    QImage image;
    QSize size;
    for (int loop = 0; loop < passed.size(); loop++) {
        if (image.load(passed.at(loop)) == false) {
            cerr << "Error cant load image file: " << passed[loop].toStdString().c_str() << endl;
            return;
        };
        if (loop == 0)size = image.size();
        if (image.size().width() != size.width())
            if (image.size().width() != size.width()) {
                cerr << "Image file at: " << passed[loop].toStdString().c_str() << " is not the same size as other images" << endl;
                return;
            }
    }
    image_locations = passed;
    center_of_rotation = image.width() / 2;
    images_ready = true;
    number_of_images = passed.size();
    cerr<<"Done setting image locations"<<endl;
    emit newModel();
}

void ModelManager::setTextureLocations(QStringList passed) {
    QImage image;
    QSize size;
    for (int loop = 0; loop < passed.size(); loop++) {
        if (image.load(passed.at(loop)) == false) {
            cerr << "Error cant load texture file: " << passed[loop].toStdString().c_str() << endl;
            return;
        };
        if (loop == 0)size = image.size();
        if (image.size().width() != size.width())
            if (image.size().width() != size.width()) {
                cerr << "Texture file at: " << passed[loop].toStdString().c_str() << " is not the same size as other images" << endl;
                return;
            }
    }
    texture_locations = passed;
    textures_ready = true;
    number_of_textures = passed.size();
    emit newModel();
}

void ModelManager::setTopCrop(int passed) {
    top_crop = passed;
    emit newModel();
}

void ModelManager::setBottomCrop(int passed) {
    bottom_crop = passed;
    emit newModel();
}

void ModelManager::setCenterOfRotation(int passed) {
    center_of_rotation = passed;
    emit newModel();
}

int ModelManager::getTopCrop() {
    return top_crop;
}

int ModelManager::getBottomCrop() {
    return bottom_crop;
}

int ModelManager::getCenterOfRotation() {
    return center_of_rotation;
}

void ModelManager::loadImages(const QStringList & selected) {
    setImageLocations(selected);
}

void ModelManager::loadTextures(const QStringList & selected) {
    setTextureLocations(selected);
}

void ModelManager::displayLoadDialog(bool passed) {
    file_opener->setVisible(true);
}

void ModelManager::displayTexDialog(bool passed) {
    tex_opener->setVisible(true);
}
/* 
 * File:   ModelManager.cpp
 * Author: matt
 * 
 * Created on 13 August 2010, 19:01
 */

#include "ModelManager.h"
ModelManager::ModelManager() {
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
    cerr<<"Unable to load image"<<image_locations.at(location).toStdString().c_str()<<endl;
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
    cerr<<"Unable to load image"<<image_locations.first().toStdString().c_str()<<endl;
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
        cerr<<"Unable to load image"<<image_locations.last().toStdString().c_str()<<endl;
    return image;
}

QImage ModelManager::getTexture(int location) {
    QImage texture;
    if (texture_locations.size() == 0) {
        texture = QImage(800, 600, QImage::Format_RGB32);
        cerr<<"Texture does not exist"<<endl;
        return texture;
    }
    if (texture.load(texture_locations.at(location)))return texture;
    texture = QImage(800, 600, QImage::Format_RGB32);
    cerr<<"Unable to load texture"<<texture_locations.at(location).toStdString().c_str()<<endl;
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
        cerr<<"Unable to load texture"<<texture_locations.first().toStdString().c_str()<<endl;
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
        cerr<<"Unable to load texture"<<texture_locations.last().toStdString().c_str()<<endl;
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

void ModelManager::setImageLocations(QStringList passed) {
    QImage image;
    QSize size;
    for (int loop = 0; loop < passed.size(); loop++) {
        if (image.load(passed.at(loop)) == false) {
            cerr<<"Error cant load texture file: " << passed[loop].toStdString().c_str() << endl;
            return;
        };
        if (loop == 0)size = image.size();
        if(image.size().width() != size.width())
            if(image.size().width() != size.width())
            {
                cerr<<"Image file at: "<<passed[loop].toStdString().c_str()<<" is not the same size as other images"<<endl;
                return;
            }
        }
    image_locations = passed;
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
        if(image.size().width() != size.width())
            if(image.size().width() != size.width())
            {
                cerr<<"Texture file at: "<<passed[loop].toStdString().c_str()<<" is not the same size as other images"<<endl;
                return;
            }
        }
    texture_locations = passed;
}

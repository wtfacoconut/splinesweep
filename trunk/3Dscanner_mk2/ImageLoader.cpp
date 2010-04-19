/* 
 * File:   ImageLoader.cpp
 * Author: matt
 * 
 * Created on 29 January 2010, 11:36
 */

#include "ImageLoader.h"

ImageLoader::ImageLoader(QWidget *parent, const char *name) {
    layout = new QHBoxLayout(this);
    file_opener = new QFileDialog();
    file_opener->setNameFilter(tr("Images (*.png *.bmp *.jpg *.jpeg)"));
    file_opener->setFileMode(QFileDialog::ExistingFiles);
    file_opener->setVisible(false);
    tex_opener = new QFileDialog();
    tex_opener->setNameFilter(tr("Images (*.png *.bmp *.jpg *.jpeg)"));
    tex_opener->setFileMode(QFileDialog::ExistingFiles);
    tex_opener->setVisible(false);
    QPushButton *load_button = new QPushButton("Load Images");
    QPushButton *next_button = new QPushButton("Next Image");
    QPushButton *prev_button = new QPushButton("Prev Image");
    QPushButton *load_textures = new QPushButton("Load Textures");
    layout->addWidget(load_button);
    layout->addWidget(prev_button);
    layout->addWidget(next_button);
    layout->addWidget(load_textures);

    connect(load_button, SIGNAL(clicked(bool)), this, SLOT(displayLoadDialog(bool)));
    connect(load_textures, SIGNAL(clicked(bool)), this, SLOT(displayTexDialog(bool)));
    connect(prev_button, SIGNAL(clicked(bool)), this, SLOT(nextImage(bool)));
    connect(next_button, SIGNAL(clicked(bool)), this, SLOT(prevImage(bool)));
    connect(file_opener, SIGNAL(filesSelected(const QStringList &)), this, SLOT(loadImages(const QStringList &)));
    connect(tex_opener, SIGNAL(filesSelected(const QStringList &)), this, SLOT(loadTextures(const QStringList &)));
    image_index = 0;
}

ImageLoader::~ImageLoader() {
}

void ImageLoader::loadImages(const QStringList & selected) {
    image_list.clear();
    image_index = 0;
    int num_files = selected.length();

    for (int loop = 0; loop < num_files; loop++) {
        QImage image;
        image.load(selected.at(loop));
        image_list.push_back(image);
    }
    if (image_list.size() > 0) {

        emit newNumImages(image_list.size());
        /*for(int loop =0 ;loop <image_list.size();loop++)
        {
           emit newImage(image_list.at(loop));
        }*/
    }
}

void ImageLoader::loadTextures(const QStringList & selected) {
    tex_list.clear();
    tex_index = 0;
    int num_files = selected.length();

    for (int loop = 0; loop < num_files; loop++) {
        QImage image;
        image.load(selected.at(loop));
        tex_list.push_back(image);
    }
    if (tex_list.size() > 0) {
        //emit newNumImages(image_list.size());
        /*for(int loop =0 ;loop <image_list.size();loop++)
        {
           emit newImage(image_list.at(loop));
        }*/
    }
}

void ImageLoader::displayLoadDialog(bool passed) {
    file_opener->setVisible(true);
}

void ImageLoader::displayTexDialog(bool passed) {
    tex_opener->setVisible(true);
}

void ImageLoader::nextImage(bool passed) {
    if (image_list.size() > 0) {
        image_index++;
        if (image_index == image_list.size()) {
            image_index = 0;
        }
        emit newImage(image_list.at(image_index));
        if(image_list.size() == tex_list.size())
        {
            emit newTexture(tex_list.at(image_index));
        }else
        {
            cerr<<"No or too few texture images loaded"<<endl;
        }
    }
}

void ImageLoader::prevImage(bool passed) {
    if (image_list.size() > 0) {
        image_index--;
        if (image_index == -1) {
            image_index = image_list.size() - 1;
        }
        emit newImage(image_list.at(image_index));
                if(image_list.size() == tex_list.size())
        {
            emit newTexture(tex_list.at(image_index));
        }else
        {
            cerr<<"No or too few texture images loaded"<<endl;
        }
    }
}

int ImageLoader::getNumImages() {
    return image_list.size();
}
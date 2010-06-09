/* 
 * File:   ImageLoader.h
 * Author: matt
 *
 * Created on 29 January 2010, 11:36
 */

#ifndef _IMAGELOADER_H
#define	_IMAGELOADER_H

//Standard Includes
#include <stdlib.h>
#include <iostream>
using namespace std;
//Qt Includes
#include <QWidget>
#include <QImage>
#include <QList>
#include <QFileDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMatrix>

class ImageLoader : public QWidget {
    Q_OBJECT
public:
    ImageLoader(QWidget *parent = 0, const char *name = 0);
    virtual ~ImageLoader();
    int getNumImages();
public slots:
        void nextImage(bool passed);
    void prevImage(bool passed);
signals:
    void newImage(QImage image);
    void newTexture(QImage image);
    void newNumImages(int num);
private:
    QFileDialog *file_opener;
    QFileDialog *tex_opener;
    QHBoxLayout *layout;
    QStringList image_list;
    int image_index;
    QStringList tex_list;
    int tex_index;


private slots:
    void loadImages(const QStringList & selected);
    void loadTextures(const QStringList & selected);
    void displayLoadDialog(bool passed);
    void displayTexDialog(bool passed);

};

#endif	/* _IMAGELOADER_H */


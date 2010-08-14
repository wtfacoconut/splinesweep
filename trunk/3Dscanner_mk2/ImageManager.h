/* 
 * File:   ImageManager.h
 * Author: matt
 *
 * Created on 13 August 2010, 19:01
 */

#ifndef _ImageManager_H
#define	_ImageManager_H
#include "common.h"
#include "ImageDisplay.h"
#include "TextureDisplay.h"
#include <QStringList>
#include <QFileDialog>

using namespace std;

class ImageManager : public QWidget {
    Q_OBJECT
public:
    ImageManager();
    virtual ~ImageManager();
    QImage getImage(int location);
    QImage getFirstImage();
    QImage getLastImage();
    QImage getTexture(int location);
    QImage getFirstTexture();
    QImage getLastTexture();
    QVector<QVector <int> > getSplines();
    QVector<int> getSpline(int x);
    int getPoint(int x, int y);
    QImage getSplineImage(int location);
    void setSpline(QVector<int> passed);;
    
    bool textures_ready;
    bool images_ready;
    bool splines_ready;
    int number_of_images;
    int number_of_textures;

public slots:
    void setImageLocations(QStringList passed);
    void setTextureLocations(QStringList passed);
    void setParameters(Parameters passed);
signals:
    void newModel();
private:
    QFileDialog *file_opener;
    QFileDialog *tex_opener;
    QGridLayout *layout;
    ImageDisplay *image_display;
    TextureDisplay *texture_display;

    QStringList image_locations;
    QStringList texture_locations;
    QVector<QVector <int> > splines;
    int top_crop;
    int bottom_crop;
    double center_of_rotation;
    int image_index;
    Parameters params;

private slots:
    void loadImages(const QStringList & selected);
    void loadTextures(const QStringList & selected);
    void displayLoadDialog(bool passed);
    void displayTexDialog(bool passed);
    void nextImage(bool passed);
    void prevImage(bool passed);
};

#endif	/* _ImageManager_H */

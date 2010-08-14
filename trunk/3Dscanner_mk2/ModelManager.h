/* 
 * File:   ModelManager.h
 * Author: matt
 *
 * Created on 13 August 2010, 19:01
 */

#ifndef _MODELMANAGER_H
#define	_MODELMANAGER_H
#include "common.h"
#include <QStringList>
#include <QFileDialog>
using namespace std;

class ModelManager : public QWidget {
    Q_OBJECT
public:
    ModelManager();
    virtual ~ModelManager();
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
    void setTopCrop(int passed);
    void setBottomCrop(int passed);
    void setCenterOfRotation(int passed);
    int getTopCrop();
    int getBottomCrop();
    double getCenterOfRotation();
    
    bool textures_ready;
    bool images_ready;
    bool splines_ready;
    int number_of_images;
    int number_of_textures;

public slots:
    void setImageLocations(QStringList passed);
    void setTextureLocations(QStringList passed);
signals:
    void newModel();
private:
    QFileDialog *file_opener;
    QFileDialog *tex_opener;
    QGridLayout *layout;

    QStringList image_locations;
    QStringList texture_locations;
    QVector<QVector <int> > splines;
    int top_crop;
    int bottom_crop;
    double center_of_rotation;

private slots:
    void loadImages(const QStringList & selected);
    void loadTextures(const QStringList & selected);
    void displayLoadDialog(bool passed);
    void displayTexDialog(bool passed);
};

#endif	/* _MODELMANAGER_H */


/* 
 * File:   ModelGen.h
 * Author: matt
 *
 * Created on 29 March 2010, 17:04
 */

#ifndef _MODELGEN_H
#define	_MODELGEN_H
#include "common.h"
#include <fstream>
#define pi 3.14159265

struct Point3D {
    int x;
    int y;
    int z;
};

class ModelGen : public QObject {
    Q_OBJECT
public:
    ModelGen();
    virtual ~ModelGen();
    
private:
    void process();
    void saveModel();
    QList<QImage> image_list;
    QList<QImage> tex_list;
    QList<Point3D> point_list3D;
    QVector<QVector<QPoint> > point_list2D;
    int image_index;
    int num_images;
    double scale_factor;
    QImage texture;

private slots:
    void setImage(QImage passed);
    void setTexture(QImage passed);
    void setNumImages(int passed);
    void createTexture();
    double radianToDegree(double radian);
    double degreeToRadian(double degree);

};

#endif	/* _MODELGEN_H */


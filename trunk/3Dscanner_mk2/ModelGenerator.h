/* 
 * File:   ModelGenerator.h
 * Author: matt
 *
 * Created on 10 June 2010, 18:15
 */

#ifndef _MODELGENERATOR_H
#define	_MODELGENERATOR_H
#include "common.h"
#include "ImageManager.h"
#include <math.h>

using namespace std;

struct point {
    int x;
    int y;
    int z;
};

class ModelGenerator : public QWidget {
    Q_OBJECT
public:
    ModelGenerator();
    virtual ~ModelGenerator();
    void generateModel(QVector< QVector<int> > passed,QString passed_name);
public slots:
    void setParameters(Parameters passed);
    void setImageManager(ImageManager *passed);
    void setSplines(QVector< QVector<int> > passed);
signals:
private slots:
    void setLaserAngle(double passed);
private:
    double laserAngle;
    QGridLayout *layout;
    Parameters params;
    ImageManager *image_manager;
    QVector< QVector <int> > splines;
    QVector< QVector <point> > mesh;
    QImage texture;
    QString filename;
};

#endif	/* _MODELGENERATOR_H */


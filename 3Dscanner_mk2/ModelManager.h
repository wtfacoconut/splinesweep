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

    int top_crop;
    int bottom_crop;
    int center_of_rotation;

public slots:
    void setImageLocations(QStringList passed);
    void setTextureLocations(QStringList passed);
signals:
private:
    QStringList image_locations;
    QStringList texture_locations;
    QVector<QVector <int> > splines;
};

#endif	/* _MODELMANAGER_H */


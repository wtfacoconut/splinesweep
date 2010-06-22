/* 
 * File:   ModelGenerator.h
 * Author: matt
 *
 * Created on 10 June 2010, 18:15
 */

#ifndef _MODELGENERATOR_H
#define	_MODELGENERATOR_H
#include "common.h"

class ModelGenerator : public QWidget {
    Q_OBJECT
public:
    ModelGenerator();
    virtual ~ModelGenerator();

public slots:
    void setEnableTexture(bool passed);
    void setNumImages(int passed);
    void setImage(QImage passed);
    void setTexture(QImage passed);

signals:
    void requestImage(int passed);
    void requestTexture(int passed);
    void newImage(QImage passed);
    void newTexture(QImage passed);
    void newCenterOfRotation(int passed);

private slots:
    void generate(bool passed);
    void setTopCrop(int passed);
    void setBottomCrop(int passed);
    void setCenterOfRotation(int passed);

private:
    void addSpline();
    void process();
    QImage crop(QImage passed);
    bool enable_texture;
    QImage current_texture;
    QImage current_spline;


    QGridLayout *layout;
    QPushButton *generate_button;
    QSpinBox *top_crop_spinbox;
    QSpinBox *bottom_crop_spinbox;
    QSpinBox *center_spinbox;
    bool enabled;
    int num_images;
    int center_of_rotation;
    int top_crop;
    int bottom_crop;
    QVector<QVector <QRgb> > texture_map;
    QVector<QVector <double> > depth_map;
};

#endif	/* _MODELGENERATOR_H */


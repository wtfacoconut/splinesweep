/* 
 * File:   ModelManager.h
 * Author: matt
 *
 * Created on 14 August 2010, 18:34
 */

#ifndef _MODELMANAGER_H
#define	_MODELMANAGER_
#include "common.h"
#include "ImageManager.h"
#include "SplineGenerator.h"
#include "SplineDisplay.h"
#include "ModelGenerator.h"

class ModelManager : public QWidget {
    Q_OBJECT
public:
    ModelManager();
    virtual ~ModelManager();
    void setImageManager(ImageManager *passed);

public slots:
    void generateSplines(bool passed);
    void updateSplineImage(int index);
    signals:
    void newParameters(Parameters params);

private slots:
    void newTopCrop(double passed);
    void newBottomCrop(double passed);
    void newCenter(double passed);

private:
    QImage getSplineImage(int location);
    void initCropControls();

    ModelGenerator *model_generator;
    ImageManager *image_manager;
    SplineGenerator *spline_generator;
    SplineDisplay *spline_display;
    QVector< QVector<int> >splines;
    QGridLayout *layout;
    QGridLayout *crop_layout;
    QTabWidget *options_tabs;
    bool splines_ready;
    int width;
    Parameters params;

};

#endif	/* _MODELMANAGER_H */


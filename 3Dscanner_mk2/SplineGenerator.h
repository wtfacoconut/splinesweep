/* 
 * File:   SplineGenerator.h
 * Author: matt
 *
 * Created on 09 June 2010, 18:55
 */

#ifndef _SPLINEGENERATOR_H
#define	_SPLINEGENERATOR_H
#include "common.h"

class SplineGenerator : public QWidget {
    Q_OBJECT
public:
    SplineGenerator();
    virtual ~SplineGenerator();
        QVector<int> process(QImage passed);
public slots:
signals:
    void newImage(QImage result);
    void requestImage();

private slots:
    void setMaxThreshold(int passed);
    void setMinThreshold(int passed);
private:
    void calcHorixontalValue();
    void threshold();

    int threshold_min;
    int threshold_max;
    QSpinBox *threshold_min_spinbox;
    QSpinBox *threshold_max_spinbox;
    QGridLayout *layout;
    QImage image;
    QVector<int> points;
};

#endif	/* _SPLINEGENERATOR_H */


/* 
 * File:   QErode.h
 * Author: matt
 *
 * Created on 20 March 2010, 16:36
 */

#ifndef _QCANNY_H
#define	_QCANNY_H
#include "common.h"

class QCanny : public QObject {
    Q_OBJECT

public:
    QCanny();
    virtual ~QCanny();
    void setVals(int passed_min, int passed_max);
public slots:
    void setImage(QImage passed_image);
signals:
    void newImage(QImage image);

private:
    void process();
    QImage image;
    double max;
    double min;
};

#endif	/* _QCANNY_H */


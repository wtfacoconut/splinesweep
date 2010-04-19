/* 
 * File:   QErode.h
 * Author: matt
 *
 * Created on 20 March 2010, 16:36
 */

#ifndef _QSMOOTH_H
#define	_QSMOOTH_H
#include "common.h"

class QSmooth : public QObject {
    Q_OBJECT

public:
    QSmooth();
    virtual ~QSmooth();

public slots:
    void setImage(QImage passed_image);
signals:
    void newImage(QImage image);

private:
    void process();
    QImage image;
};

#endif	/* _QSMOOTH_H */


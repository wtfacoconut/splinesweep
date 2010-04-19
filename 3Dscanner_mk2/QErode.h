/* 
 * File:   QErode.h
 * Author: matt
 *
 * Created on 20 March 2010, 16:36
 */

#ifndef _QERODE_H
#define	_QERODE_H
#include "common.h"

class QErode : public QObject {
    Q_OBJECT

public:
    QErode();
    virtual ~QErode();

public slots:
    void setImage(QImage passed_image);
signals:
    void newImage(QImage image);

private:
    void process();
    QImage image;
};

#endif	/* _QERODE_H */


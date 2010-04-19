/* 
 * File:   QErode.h
 * Author: matt
 *
 * Created on 20 March 2010, 16:36
 */

#ifndef _QDILATE_H
#define	_QDILATE_H
#include "common.h"

class QDilate : public QObject {
    Q_OBJECT

public:
    QDilate();
    virtual ~QDilate();

public slots:
    void setImage(QImage passed_image);
signals:
    void newImage(QImage image);

private:
    void process();
    QImage image;
};

#endif	/* _QDILATE_H */


/* 
 * File:   QChromaKey.h
 * Author: matt
 *
 * Created on 20 March 2010, 15:49
 */

#ifndef _QCHROMAKEY_H
#define	_QCHROMAKEY_H
#include "common.h"

class QChromaKey : public QObject{
    Q_OBJECT
public:
    QChromaKey();
    QChromaKey(const QChromaKey& orig);
    virtual ~QChromaKey();
    public
slots:
    void setImage(QImage passed_image);
    void setRedMax(int passed);
    void setRedMin(int passed);
    void setGreenMax(int passed);
    void setGreenMin(int passed);
    void setBlueMax(int passed);
    void setBlueMin(int passed);
    void setMaxColor(QRgb passed);
    void setMinColor(QRgb passed);
signals:
    void newImage(QImage image);

private:
    void process();
    QImage image;
    int red_max;
    int red_min;
    int green_max;
    int green_min;
    int blue_max;
    int blue_min;
    bool enable_blue;
    bool enable_red;
    bool enable_green;
};

#endif	/* _QCHROMAKEY_H */


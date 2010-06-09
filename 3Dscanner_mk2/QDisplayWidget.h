/*
 * File:   QDisplayWidget.h
 * Author: matt
 *
 * Created on 20 January 2010, 11:54
 */

#ifndef _QDISPLAYWIDGET_H
#define	_QDISPLAYWIDGET_H

//Standard Includes
#include "common.h"
#include <QMouseEvent>
#define WIDTH 320

class QDisplayWidget : public QWidget {
    Q_OBJECT
public:
    QDisplayWidget(QWidget *parent = 0, const char *name = 0);
    virtual ~QDisplayWidget();
    void paintEvent(QPaintEvent *event);

public slots:
    void setImage(QImage passed_image);
    void setAlphaChannel(QImage passed_image);
signals:
    void newImage(QImage image);

private:
    void mouseMoveEvent(QMouseEvent *event);
    QImage image;
    QImage alpha_channel;
    int image_x;
    int image_y;
};

#endif	/* _QDISPLAYWIDGET_H */


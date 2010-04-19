/*
 * File:   main.cpp
 * Author: matt
 *
 * Created on 20 March 2010, 15:34
 */

#include <QtGui/QApplication>
#include "GUI.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    QApplication app(argc, argv);

    // create and show your widgets here
    GUI *window = new GUI;
    window->setWindowTitle("3DScanner mkII");
    window->show();
    app.exec();
    delete window;
    return 0;
}

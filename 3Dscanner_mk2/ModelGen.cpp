/* 
 * File:   ModelGen.cpp
 * Author: matt
 * 
 * Created on 29 March 2010, 17:04
 */

#include "ModelGen.h"

ModelGen::ModelGen() {
    image_index = 0;
    num_images = 0;
    scale_factor = 1.4;
}

ModelGen::~ModelGen() {
}

void ModelGen::setImage(QImage passed) {
    image_list.push_back(passed);
    if (image_list.size() == num_images && (tex_list.size() == 0 || tex_list.size() == num_images)) {
        process();
    }
}

void ModelGen::setTexture(QImage passed) {
    tex_list.push_back(passed);
    if (image_list.size() == num_images && (tex_list.size() == 0 || tex_list.size() == num_images)) {
        process();
    }
}

void ModelGen::setNumImages(int passed) {
    num_images = passed;
}

void ModelGen::process() {
    point_list3D.clear();
    point_list2D.clear();
    cerr << "Creating Model" << endl;
    double angle = double((double) 360 / (double) num_images);

    //initialise the 2D point array
    cerr << "Initialise the 2D point array" << endl;
    for (int depth = 0; depth < image_list.size(); depth++) {
        QVector<QPoint> current;
        point_list2D.push_front(current);
        for (int y = 0; y < image_list.at(depth).height(); y++) {
            QPoint current_point;
            current_point.setX(0);
            current_point.setY(y);
            point_list2D.front().push_front(current_point);
        }
    }

    cerr << "Filling the 2D point array" << endl;
    for (int loop = 0; loop < image_list.size(); loop++) {
        QImage current = image_list.at(loop);
        current = current.scaled(current.width() * scale_factor, current.height());

        for (int y = 0; y < current.height(); y++) {
            for (int x = 0; x < current.width(); x++) {
                QRgb pixel = current.pixel(x, y);
                if (qRed(pixel) > 0) {
                    //double current_angle = angle*loop;
                    //Point3D current_point;
                    //current_point.x = sin(current_angle / 57.29578) * (double(current.width() / 2) - x);
                    //current_point.x = double(x/2) - current_point.x;
                    //current_point.y = y;
                    //current_point.z = cos(current_angle / 57.29578) * (double(current.width() / 2) - x);
                    //current_point.z = double(x/2) - current_point.z;
                    //point_list3D.push_back(current_point);
                    point_list2D[loop][y].setX(x);
                }
            }
        }
    }

    //find the points that need work on them
    cerr << "Finding points to work on" << endl;
    QVector<int> work;
    cerr << "Ponitlist size" << point_list2D[0].size() << endl;

    for (int y = 0; y < point_list2D[0].size(); y++) {
        int count = 0;
        for (int depth = 0; depth < point_list2D.size(); depth++) {
            if (point_list2D[depth][y].x() > 0) {
                count++;
            }
        }
        if (count > 0 && count < point_list2D.size()) {
            work.push_back(y);
        }
    }
    //fix the points that need work
    cerr << "Number of points to work on: " << work.size() << endl;
    cerr << "Fixing the points" << endl;
    for (int loop = 0; loop < work.size(); loop++) {
        //find the average of the line in question
        int count = 0;
        int avg = 0;
        for (int depth = 0; depth < point_list2D.size(); depth++) {
            if (point_list2D[depth][work.at(loop)].x() > 0) {
                avg = avg + point_list2D[depth][work.at(loop)].x();
                count++;
            }
        }
        avg = avg / count;
        //Do the fixings
        for (int depth = 0; depth < point_list2D.size(); depth++) {
            if (point_list2D[depth][work.at(loop)].x() == 0) {
                point_list2D[depth][work.at(loop)].setX(avg);
                //cerr<<"Averages: "<<avg<<endl;
            }
        }
    }

    createTexture();


    //Convert to 3D model
    for (int y = 0; y < point_list2D[0].size(); y++) {
        for (int depth = 0; depth < point_list2D.size(); depth++) {
            if (point_list2D[depth][y].x() > 0) {
                double current_angle = (double) ((double) angle * (double) depth);
                //cerr << "Current Angle: " << current_angle << endl;
                Point3D current_point;
                current_point.x = sin(current_angle / 57.29578) * (double((image_list.at(depth).width() / 2) + 20) * scale_factor - point_list2D[depth][y].x());
                //current_point.x = double(x/2) - current_point.x;
                current_point.y = y;
                current_point.z = cos(current_angle / 57.29578) * (double((image_list.at(depth).width() / 2) + 20) * scale_factor - point_list2D[depth][y].x()); //double(image_list.at(depth).width() / 2) - point_list2D[depth][y].x());
                //current_point.z = double(x/2) - current_point.z;
                point_list3D.push_front(current_point);
            }
        }
    }

    cerr << "Number of 3D points" << point_list3D.size() << endl;
    image_list.clear();
    saveModel();
}

void ModelGen::saveModel() {
    ofstream myfile;
    myfile.open("test.obj");
    for (int loop = 0; loop < point_list3D.size(); loop++) {
        myfile << "v " << point_list3D.at(loop).x << " " << point_list3D.at(loop).y << " " << point_list3D.at(loop).z << endl;
    }

    int counter=0;
    for (int y = 0; y < (point_list3D.size() / point_list2D.size()); y++) {
        for (int x = point_list2D.size()-1;x>=0 ; x--) {
            double u = (double)x/(double)texture.width();
            double v =(double)y/(double)texture.height();
            myfile<<"vt "<<u<<" "<<v<<endl;
            counter++;
        }
    }
    myfile << "mtllib test.mtl" << endl;
    myfile << "usemtl Textured" << endl;

    for (int x = (point_list3D.size() - point_list2D.size()) - 1; x >= 1; x--) {
        if (x % point_list2D.size() == 0)x--;
        if(x == 0){cerr<<"X=0 ERROR!!!!!!"<<endl;}
        if((x + point_list2D.size()+1)>counter){cerr<<"Tex cord out of range ERROR!!!!!"<<endl;}
        myfile << "f " << x<<"/"<<x<<"/" << " " << x + point_list2D.size() <<"/"<<x+ point_list2D.size()<<"/"<< " " << x + point_list2D.size() + 1 <<"/"<< x + point_list2D.size() + 1<<"/"<< " " << x + 1 <<"/"<<x+1<<"/"<< endl;
    }

    //cerr<<"LOOK HERE!!!!!:  "<<point_list2D.size()<<endl;
    //SORT THIS OUT!!
    cerr << "HEIGHT: " << (point_list3D.size() / point_list2D.size() - 1) << endl;
    int height = (point_list3D.size() / point_list2D.size());
    int width = point_list2D.size();

    cerr << "Height: " << height << " Width: " << width << endl;
    for (int x = 1; x < height - 3; x++) {
        myfile << "f " << x * width << " " << (x + 1) * width << " " << ((x + 1) * width) + width + width + 1 << " " << x * width + width + 101 << endl;
        //cerr << "f "<<x*width  <<" "<<(x+1)*width<<" "<< ((x+1)*width)+width +width+1 << " "<<x*width+width +101<<endl;
    }

    /*//height
    for (int y = 0; y < (point_list3D.size() / point_list2D.size()); y++) {
        //depth
        for (int x = 0; x < point_list2D.size(); x++) {
            myfile << "vt " << (double) x / (double) point_list2D.size() << " " << (double) y / (double) (point_list3D.size() / point_list2D.size()) << endl;
        }
    }*/


    //Write the material files
    myfile.close();
    myfile.open("test.mtl");
    myfile << "newmtl Textured" << endl <<
            "Ka 1.000 1.000 1.000" << endl <<
            "Kd 1.000 1.000 1.000" << endl <<
            "Ks 0.000 0.000 0.000" << endl <<
            "d 1.0" << endl <<
            "Tr 1.0" << endl <<
            "illum 2" << endl <<
            "map_Ka test.tga" << endl <<
            "map_Kd test.tga" << endl;
    myfile.close();


    point_list3D.clear();
}

void ModelGen::createTexture() {
    /*for(int loop=0; loop < image_list.size();loop++)
    {
    cerr<<image_list<<endl;
    }*/

    cerr << "Creating Texture" << endl;


    //find the height of the texture
    int height = 0;
    for (int y = 0; y < point_list2D[0].size(); y++) {
        if (point_list2D[0][y].x() > 0) {
            height++;
        }
    }


    texture = QImage(point_list2D.size(), height, QImage::Format_RGB32);


    for (int depth = 0; depth < point_list2D.size(); depth++) {
        QImage tex = tex_list.at(depth);
        tex = tex.scaled(tex.width() * scale_factor, tex.height());
        for (int y = point_list2D[depth].size() - height; y < point_list2D[depth].size(); y++) {
            if (point_list2D[0][y].x() > 0) {
                QRgb pixel1 = tex.pixel(point_list2D[depth][y].x(), y); //point_list2D[depth][y].y());
                /*QRgb pixel2 = tex.pixel(point_list2D[depth][y].x()+1, y);
                QRgb pixel3 = tex.pixel(point_list2D[depth][y].x()+2, y);
                QRgb pixel4 = tex.pixel(point_list2D[depth][y].x()+4, y);
                QRgb pixel5 = tex.pixel(point_list2D[depth][y].x()+5, y);*/
                texture.setPixel(depth, y - (point_list2D[depth].size() - height), pixel1);
                /*texture.setPixel(depth*5+1, y - (point_list2D[depth].size() - height), pixel2);
                texture.setPixel(depth*5+2, y - (point_list2D[depth].size() - height), pixel3);
                texture.setPixel(depth*5+3, y - (point_list2D[depth].size() - height), pixel4);
                texture.setPixel(depth*5+4, y - (point_list2D[depth].size() - height), pixel5);*/
            }
        }
    }
    cerr << "Saving Texture" << endl;
    texture.save("test.png", "png");
}

double ModelGen::radianToDegree(double radian) {
    double degree = 0;
    degree = radian * (180 / pi);
    return degree;
}

double ModelGen::degreeToRadian(double degree) {
    double radian = 0;
    radian = degree / (180 / pi);
    return radian;
}
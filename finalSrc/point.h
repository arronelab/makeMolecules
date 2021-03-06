#ifndef PNT_H
#define PNT_H
#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>


class point{
      public:
            point(double x,double y,double z);
	    point();
            point(std::string& triplet);
            double getX();
            double getY();
            double getZ();
            void setX(double xv);
            void setY(double yv);
            void setZ(double zv);
            point sum(point& b);
            point dif(point& b);
            point cross(point& p2);
	    double scalarTriple(point& p1,point& p2,point& p3);
            bool checkEqual(point& p2);
            void scalarMult(double a);
	    double pairDist(point &p);
            void normalise();
	    void znormalise();
	    void printPoint();
	    double length();
            double dotprod(point& p2);
	    bool isNonzero();
	     //point operator+(point &p);
	    point operator+(point p);
	    // point operator-(point &p);
	    point operator-(point p);
	    point operator*(double d);
	    point operator/(double d);
	    // point operator*(double d);
	    double eDist(point &p2);
      private:
            double X,Y,Z,norm;
};

#endif

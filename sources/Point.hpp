#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point();
        Point(double, double);
        double getY();
        double getX();
        string print();
        void setY(double);
        void setX(double);
        double distance(Point);
        static Point moveTowards(Point, Point, double);
    };
}

#include "Point.hpp"

namespace ariel
{
    Point::Point(double x, double y)
        : x(x), y(y) {}

    double Point::getX()
    {
        return x;
    }

    void Point::setX(double a)
    {
        x = a;
    }

    double Point::getY()
    {
        return y;
    }

    void Point::setY(double b)
    {
        y = b;
    }

    double Point::distance(Point c)
    {
        double result_X = x - c.getX();
        double result_Y = y - c.getY();
        double distance = std::sqrt(result_X * result_X + result_Y * result_Y);
        return distance;
    }

    string Point::print()
    {
        cout << "the coordinates is : (" << to_string(x) << "," << to_string(y) << ")" << endl;
        return "";
    }

    Point Point::moveTowards(Point source, Point destination, double MaxDistance)
    {
        if (source.distance(destination) <= MaxDistance)
            return destination;
        if (MaxDistance == 0)
            return source;
        if (MaxDistance < 0)
            throw invalid_argument("the distance should be only positive");
        double deltaX = destination.x - source.x;
        double deltaY = destination.y - source.y;
        double scale = MaxDistance / source.distance(destination);
        return Point(source.x + scale * deltaX, source.y + scale * deltaY);
    }
}
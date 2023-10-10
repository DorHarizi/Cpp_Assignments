#pragma once

#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x; // x-coordinate
        double y; // y-coordinate

    public:
        // Constructor: initializes Point with given x and y
        Point(double x11, double y11);

        // Getter for x
        double getX();

        // Getter for y
        double getY();

        // Setter for x
        void setX(double x11);

        // Setter for y
        void setY(double y11);

        // Calculates distance to destination Point
        double distance(Point dest);

        // Moves towards destination by given distance
        static Point moveTowards(Point src, Point dest, double distance);

        // Returns string representation of Point
        string print();
    };
}

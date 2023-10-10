#pragma once

#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x; // x-coordinate of the Point
        double y; // y-coordinate of the Point

    public:
        // Constructor initializes a Point with given x and y coordinates
        // @param x11: x-coordinate of the Point
        // @param y11: y-coordinate of the Point
        Point(double x11, double y11);

        // Getter function for x-coordinate
        // @return: x-coordinate of the Point
        double getX();

        // Getter function for y-coordinate
        // @return: y-coordinate of the Point
        double getY();

        // Setter function for x-coordinate
        // @param x11: new x-coordinate of the Point
        void setX(double x11);

        // Setter function for y-coordinate
        // @param y11: new y-coordinate of the Point
        void setY(double y11);

        // Calculates and returns the distance to destination Point
        // @param dest: destination Point
        // @return: distance between this Point and dest
        double distance(Point dest);

        // Returns a new Point that is moved towards the destination Point
        // @param src: starting Point
        // @param dest: destination Point
        // @param distance: maximum distance to move towards dest
        // @return: new Point closest to dest within given distance from src
        static Point moveTowards(Point src, Point dest, double distance);

        // Generates and returns a string representation of the Point
        // @return: string representing the Point's coordinates
        string print();
    };
}

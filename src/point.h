#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point 
{
    protected:
        float x, y, z;

    public:
        // Constructors
        Point();
        Point(float, float, float);

        // Accessors
        float X() {return this->x;} 
        float Y() {return this->y;} 
        float Z() {return this->z;} 
        
        // Mutators
        void setX(float X) {this->x = X;}      
        void setY(float Y) {this->y = Y;}
        void setZ(float Z) {this->z = Z;}

        // Other functions
        Point * norm();
        float   dist(Point*);

        // Operator overloads
        Point * operator+ (Point);
        Point * operator- (Point);
        Point * operator/ (Point);
        Point * operator* (Point);
        Point * operator+=(Point);
        Point * operator-=(Point);
        Point * operator/=(Point);
        Point * operator*=(Point);
        Point * operator= (Point);
        bool    operator==(Point);

        Point * operator+ (float);
        Point * operator- (float);
        Point * operator/ (float);
        Point * operator* (float);
        Point * operator+=(float);
        Point * operator-=(float);
        Point * operator/=(float);
        Point * operator*=(float);
        
        friend std::ostream& operator<< (std::ostream&, Point *);
};

// 3D ray class that inherits from point.
class Ray : public Point
{
    protected:
        float posx, posy, posz;
        int R, G, B; // Returned color value
        float d;     // Distance to closest object
    public:
        Ray();
        Ray(float, float, float, float, float, float);
        Ray(Point*, Point *);

        void setColor(int, int, int);
        Point * propagate(float);
};

#endif

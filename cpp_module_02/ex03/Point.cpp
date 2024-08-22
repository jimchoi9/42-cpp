#include "Point.hpp"

Point::Point(const Fixed &x, const Fixed &y):x(x),y(y){}

Point::Point(const Point &a):x(a.getX()), y(a.getY()){}
Point::~Point(){}

// Point &Point::operator=(const Point &a){
// 	return a;
// }

Fixed Point::getX() const{
    return x;
}

Fixed Point::getY() const{
    return y;
}
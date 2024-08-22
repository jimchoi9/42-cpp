#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
std::ostream &operator<<(std::ostream &os, const Fixed &a);
bool isInsideTriangle(const Point &a, const Point &b, const Point &c, const Point &point);

int main( void ) {
	Fixed aX(1); Fixed aY(1);

	Fixed bX(5); Fixed bY(1);

	Fixed cX(1); Fixed cY(5);

	Fixed dX(7); Fixed dY(2);

	Point a(aX, aY);
	Point b(bX, bY);
	Point c(cX, cY);
	Point d(dX, dY);

	if (isInsideTriangle(a, b, c, d))
		std::cout << "Point is inside" << std::endl;
	else
		std::cout << "Point is outside" << std::endl;

	return 0;
}
#include "Point.hpp"
#include "Fixed.hpp"


Fixed getTriangleArea(const Point &a, const Point &b, const Point &c){
	Fixed s = (b.getX() - a.getX())*(c.getY() - a.getY() - (c.getX() - a.getX())*(c.getY() - a.getY()));
	s > 0 ? s = s * 1 : s = s * -1;
	return s / 2;
}

bool isInsideTriangle(const Point &a, const Point &b, const Point &c, const Point &point){
	Fixed d1, d2, d3, s;

	d1 = getTriangleArea(a, b, point);
	d2 = getTriangleArea(b, c, point);
	d3 = getTriangleArea(c, a, point);
	s = getTriangleArea(a, b, c);

	return !((d1 + d2 + d3) > s);
}
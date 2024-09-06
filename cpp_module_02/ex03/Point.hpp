#include "Fixed.hpp"

class Point {

	public:
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &a);
		~Point();
		Fixed getX()const;
		Fixed getY()const;
		Point &operator=(const Point &a);
	private:
		Fixed const x;
		Fixed const y;
		Point();
};
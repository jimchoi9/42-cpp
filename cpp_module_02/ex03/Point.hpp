#include "Fixed.hpp"

class Point {

	public:
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &a); //Copy Constructor (복사생성자)
		~Point(); //Destructor (소멸자)
		// Point &operator=(const Point &a);
		Fixed getX()const;
		Fixed getY()const;
	private:
		Fixed const x;
		Fixed const y;
		Point();
};
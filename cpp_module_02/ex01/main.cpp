#include <iostream>
#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, const Fixed &a);

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;


	std::cout << a.toFloat() << std::endl;
	std::cout << c.toFloat() << std::endl;
	std::cout << c.toFloat() * a.toFloat() << std::endl;
	int num = ((long)c.getRawBits() * a.getRawBits()) / (1 << 8);
	std::cout << "Raw bits of c are: " << num << std::endl;
	std::cout << "Raw bits of c are: " << (float)num /(1 << 8)<< std::endl;
	std::cout << c.toFloat() / a.toFloat() << std::endl;
	int num2 = ((long)c.getRawBits() * (1 << 8)) / a.getRawBits();
	std::cout << "Raw bits of c are: " << num2 << std::endl;
	std::cout << "Raw bits of c are: " << (float)num2 /(1 << 8)<< std::endl;

    return 0;

	return 0;
}
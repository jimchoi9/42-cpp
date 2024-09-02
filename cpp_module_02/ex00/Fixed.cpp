#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
	
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &a) :num(a.num)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
	{
		this->num = a.getRawBits();
	}
	return *this;
}


int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}
void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}
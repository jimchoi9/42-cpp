#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{	std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int &a) : num(a << f_bits)
{	std::cout << "Int constructor called" << std::endl;	}

Fixed::Fixed(const float &a) : num (static_cast<int>(roundf(a * (1 << f_bits))))
{	std::cout << "Float constructor called" << std::endl;}

Fixed::~Fixed()
{	std::cout << "Destructor called" << std::endl;}

Fixed::Fixed(const Fixed &a) :num(a.num)
{	std::cout << "Copy constructor called" << std::endl;	}
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
{return this->num;}

void Fixed::setRawBits(int const raw)
{	this->num = raw;}

float Fixed::toFloat( void ) const
{	return static_cast<float>(this->num) / (1 << f_bits);}

int Fixed::toInt( void ) const
{	return this->num >> f_bits;}

std::ostream &operator<<(std::ostream &os, const Fixed &a)
{
	os << a.toFloat();
    return os;
}

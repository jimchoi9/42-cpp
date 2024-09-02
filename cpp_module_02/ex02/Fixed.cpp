#include "Fixed.hpp"

Fixed::Fixed() : num(0){}

Fixed::Fixed(const int &a) : num(a << f_bits){}

Fixed::Fixed(const float &a) : num (static_cast<int>(roundf(a * (1 << f_bits)))){}

Fixed::~Fixed(){}


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

bool Fixed::operator>(const Fixed &a){
	return this->getRawBits() > a.getRawBits();
}
bool Fixed::operator<(const Fixed &a){
	return this->getRawBits() < a.getRawBits();
}
bool Fixed::operator>=(const Fixed &a){
	return this->getRawBits() >= a.getRawBits();
}
bool Fixed::operator<=(const Fixed &a){
	return this->getRawBits() <= a.getRawBits();
}
bool Fixed::operator==(const Fixed &a){
	return this->getRawBits() == a.getRawBits();
}
bool Fixed::operator!=(const Fixed &a){
	return this->getRawBits() != a.getRawBits();
}

Fixed &Fixed::operator+(const Fixed &a){
	this->num += a.getRawBits();
	return *this;
}
Fixed &Fixed::operator-(const Fixed &a){
	this->num -= a.getRawBits();
	return *this;
}
Fixed &Fixed::operator*(const Fixed &a){
	this->num = static_cast<long>(this->getRawBits()) * a.getRawBits() / (1 << f_bits);
	return *this;
}
Fixed &Fixed::operator/(const Fixed &a){
	this->num = static_cast<long>(this->getRawBits()) * (1 << f_bits) / a.getRawBits();
	return *this;
}

Fixed &Fixed::operator++(){
	this->num++;
	return *this;
} // 전위
Fixed Fixed::operator++(int){
	Fixed temp(this->toFloat());
	this->num++;
	return temp;
} // 후위 int 는 컴파일러에게 알려주기 위한 더미값
Fixed &Fixed::operator--(){
	this->num--;
	return *this;
} // 전위
Fixed Fixed::operator--(int){
	Fixed temp(this->toFloat());
	this->num--;
	return temp;
} // 후위

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a <= b ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	Fixed tempA(a.toFloat());
	Fixed tempB(b.toFloat());
	return tempA <= tempB ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a >= b ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	Fixed tempA(a.toFloat());
	Fixed tempB(b.toFloat());
	return tempA >= tempB ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &a)
{
	os << a.toFloat();
    return os;
}

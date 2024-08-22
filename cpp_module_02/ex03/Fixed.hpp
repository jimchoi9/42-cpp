#pragma once
#include <iostream>
#include <cmath>

class Fixed {

    
	public:
		Fixed(); //Default Constructor (기본 생성자)
		Fixed(const Fixed &a); //Copy Constructor (복사생성자)
		~Fixed(); //Destructor (소멸자)
		Fixed &operator=(const Fixed &a); //Copy Assignment operator (복사 할당 연산자)

		Fixed(int const &a); //Constructor (const int 생성자)
		Fixed(float const &a); //Constructor (float 생성자)

		bool operator>(const Fixed &a);
		bool operator<(const Fixed &a);
		bool operator>=(const Fixed &a);
		bool operator<=(const Fixed &a);
		bool operator==(const Fixed &a);
		bool operator!=(const Fixed &a);

		Fixed &operator+(const Fixed &a);
		Fixed &operator-(const Fixed &a);
		Fixed &operator*(const Fixed &a);
		Fixed &operator/(const Fixed &a);

		Fixed &operator++(); // 전위
		Fixed operator++(int); // 후위 int 는 컴파일러에게 알려주기 위한 더미값
		Fixed &operator--(); // 전위
		Fixed operator--(int); // 후위

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits( void ) const; //고정소수점 값의 원시값 반환
		void setRawBits( int const raw ); // 고정소수점 수의 원시값 설정
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
	    int num; //고정소수점 값의 정수값
		static int const f_bits = 8; //소수부 비트 수를 저장 , 정수 리터럴 8
};


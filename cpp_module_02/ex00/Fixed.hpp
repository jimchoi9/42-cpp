#pragma once

class Fixed {

    
	public:
		Fixed(); //Default Constructor (기본 생성자)
		Fixed(const Fixed &a); //Copy Constructor (복사생성자)
		Fixed &operator=(const Fixed &a); //Copy Assignment operator (복사 할당 연산자)
		~Fixed(); //Destructor (소멸자)
		int getRawBits( void ) const; //고정소수점 값의 원시값 반환
		void setRawBits( int const raw ); // 고정소수점 수의 원시값 설정
	private:
	    int num; //고정소수점 값의 정수값
		static int const f_bits; //소수부 비트 수를 저장 , 정수 리터럴 8
};
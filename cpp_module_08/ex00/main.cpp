#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <algorithm>

int main( void ) {

	std::vector<int> v(5, 0); // 0으로 된 5개의 원소를 가진 벡터 생성
	v.clear();
	v.push_back( 1 );
	v.push_back( 3 );
	v.push_back( 8 );
	v.push_back( 2 );
	v.push_back( 9 );

	try {
	std::vector<int>::iterator iter = easyfind(v, 0);
	std::cout << *iter << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	try {
	std::vector<int>::iterator iter = easyfind(v, 9);
	std::cout << *iter << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "======================================================================\n";

	std::deque<int> d;
	d.push_back( 7 ); //뒤에 원소 추가
	d.push_back( 4 );
	d.push_front( 2 ); // 앞에 원소 추가
	d.push_front( 1 );

	d.insert(d.begin()+2, 3); // 3번째 위치에 5 추가
	d.erase(d.begin()+3); // 4번째 원소 삭제

	for(size_t i=0; i<d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << "front " << d.front() << " end " << d.back() << std::endl; // 첫번째, 마지막 값 접근

	try {
	std::deque<int>::iterator iter = easyfind(d, 1);
	std::cout << *iter << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
	std::deque<int>::iterator iter = easyfind(d, 9);
	std::cout << *iter << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
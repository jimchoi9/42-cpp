#pragma once
#include <iostream>
#include <string>


class Brain{

	public:
		Brain();
		~Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		std::string getIdea(const int &idx) const;
		void setIdea(const std::string &idea);
	private:
		std::string ideas[100];
		int idx;
};
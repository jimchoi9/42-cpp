#pragma once
#include <iostream>
#include <string>


class Brain{

	public:
		Brain();
		~Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		std::string getIdea(int i) const;
		void setIdea(int i, const std::string &idea);
		int getSize() const;
		void setSize(const int &num);
	private:
		std::string ideas[100];
};
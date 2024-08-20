
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid arguments" << std::endl;
		return 1;
	}
	std::ifstream infile(argv[1]);

	std::string str1 = argv[2];
	std::string str2 = argv[3];
	std::string buf;

	if (str1.empty())
	{
		std::cout << "invalid arguments" << std::endl;
        return 1;
	}

	if (!infile.is_open())
	{
		std::cout << "file open error" << std::endl;
        return 1;
	}
	std::string infileStr = argv[1];
	std::string outfileStr = infileStr += ".replace";
	std::ofstream outfile(outfileStr.c_str(), std::ios::out);
	if (!outfile.is_open())
	{
		std::cout << "file open error" << std::endl;
        return 1;
	}

	std::stringstream ss;
	ss << infile.rdbuf();
	std::string sss = ss.str();

	int index;
	std::string tmp;
	while (sss.find(str1) != std::string::npos)
	{
		index = sss.find(str1);
		tmp += sss.substr(0, index) + str2;
		sss.erase(0, index + str1.size());
	}
	if (sss.size()) tmp += sss;
	outfile << tmp;

}
//제출할 파일	`Makefile, main.cpp, *.cpp, *.
//금지된 함수	std::string::replace



#include <iostream>
#include <fstream>
#include <string>


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
	while(infile)
	{
		std::getline(infile, buf);
		for (size_t i = 0; i < buf.size(); i++)
		{
			if (buf[i] == str1[0])
			{
				if (!std::strncmp(buf.c_str() + i, str1.c_str(), str1.size()))
				{
                    buf.erase(i, str1.size());
					buf.insert(i, str2);
                }
			}
		}
		outfile << buf << std::endl;
	}
}
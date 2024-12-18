#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


class BitcoinExchange {
	public:
		BitcoinExchange(char *inputData);
		~BitcoinExchange();

		void readData();
		bool isValidDate(const std::string& dateStr);
		void calculateBitcoinCost();
		bool checkInputData(std::string &line);


	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		std::map<std::string, float> _data;
		std::string _dataPath;
		std::string _inputDataPath;
};

#endif
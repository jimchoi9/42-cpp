#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *inputData) :  _dataPath("./data.csv"), _inputDataPath(inputData) {
	readData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
		_dataPath = other._dataPath;
		_inputDataPath = other._inputDataPath;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::readData() {

	// std::ifstream file(_dataPath);
	std::ifstream file;
	file.open(_dataPath.c_str());
	if (!file.is_open()) {
		throw std::out_of_range("Error: could not open file.");
	}

	std::string line;
	std::getline(file, line); // 헤더 제거
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		std::string rate = line.substr(line.find(',') + 1);
		std::istringstream iss(rate);
		float rateFloat;
		if (!(iss >> rateFloat)) {
			std::cout << "Error: invalid number format in data file."<< std::endl;
			return;
		}
		_data[date] = rateFloat; 
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {

    if (dateStr.length() != 11 || dateStr[4] != '-' || dateStr[7] != '-' || dateStr[10] != ' ') {
        return false;
    }

    std::istringstream iss1(dateStr.substr(0, 4));
    std::istringstream iss2(dateStr.substr(5, 2));
    std::istringstream iss3(dateStr.substr(8, 2));
    int year, month, day;
    
    if (!(iss1 >> year) || !(iss2 >> month) || !(iss3 >> day)) {
        return false;
    }

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	// 1~7월 홀수 달 31일
	// 8~ 12월 짝수 달 31일
	int lastDay;
	if (month == 2) {
		lastDay = isLeapYear ? 29 : 28;
	}
	else if (month <= 7) {
		lastDay = (month % 2 == 1) ? 31 : 30;
	}
	else
		lastDay = (month % 2 == 0) ? 31 : 30;
	
	if (year < 1)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day > lastDay)
		return false;

	return true;
}

void BitcoinExchange::calculateBitcoinCost() {
	// std::ifstream inputFile(_inputDataPath);
	std::ifstream inputFile;
	inputFile.open(_inputDataPath.c_str());

	if (!inputFile.is_open()) {
		throw std::out_of_range("Error: could not open file.");
	}
	try {

	std::string line;

	getline(inputFile, line);
	if (line != "date | value") {
			std::cout << "Error: Invalid file format" << std::endl;
			return;
	}
	while (std::getline(inputFile, line)) {
		if (checkInputData(line) == false) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, line.find('|'));
		date = date.substr(0, date.find_last_not_of(" \t") + 1); // 뒤에있는 ' ' 이나 '\t' 만나기 전까지

		std::string valueStr = line.substr(line.find('|') + 1);
		valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));// 앞에있는 ' ' 이나 '\t' 를 무시하고 시작
		std::istringstream iss(valueStr);
		float value;
		iss >> value;

		if (value < 0.0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value > 1000.0) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = _data.upper_bound(date); // 같거나 큰 값중 가장 작은 값
		if (it == _data.begin()) {
			std::cout << "Error: date out of range" << std::endl;
			continue;
		}
		it--;
		float result = it->second * value;
		std::cout << date << " => " << value << " = " << result << std::endl;
		
	}
	} catch (std::exception &e) {
		inputFile.close();
		throw e;
	}
	inputFile.close();
}

bool BitcoinExchange::checkInputData(std::string &line) {
	if (line.empty()) {
		return false;
	}
	size_t delimiter = line.find("|");
	if (delimiter == std::string::npos) {
		return false;
	}
	std::string date = line.substr(0, delimiter);
	if (!isValidDate(date)) {
		return false;
	}

	std::string valueStr = line.substr(delimiter + 1);

	if (valueStr.empty()) {
		return false;
	}
	std::istringstream iss(valueStr);
	float value;
	if (!(iss >> value)) {
		return false;
	}
	return true;
}



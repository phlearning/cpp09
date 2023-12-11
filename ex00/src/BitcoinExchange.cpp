/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:36 by pvong             #+#    #+#             */
/*   Updated: 2023/12/11 16:40:27 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

BitcoinExchange::BitcoinExchange(void) {
    if (SHOWMSG)
        std::cout << COLOR("BitcoinExchange default constructor called", GREEN) << std::endl;
    return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    if (SHOWMSG)
        std::cout << COLOR("BitcoinExchange copy constructor called", GREEN) << std::endl;
    *this = src;
    return;
}

BitcoinExchange::~BitcoinExchange(void) {
    if (SHOWMSG)
        std::cout << COLOR("BitcoinExchange destructor called", RED) << std::endl;
    return;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    if (SHOWMSG)
        std::cout << COLOR("BitcoinExchange assignation operator called", GREEN) << std::endl;
    this->_filename = rhs.getFilename();
    this->_data = rhs.getData();
    return *this;
}

/* ----------------------------- My constructor ----------------------------- */

BitcoinExchange::BitcoinExchange(std::string const &filename) {

    if (!tryOpenFile(filename))
        return;
    if (SHOWMSG)
        std::cout << COLOR("BitcoinExchange constructor called", GREEN) << std::endl;
    this->_filename = filename;
    this->_data = this->_readFile("data.csv");
    return;
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

std::string BitcoinExchange::getFilename(void) const {
    return this->_filename;
}

std::map<std::string, float> BitcoinExchange::getData(void) const {
    return this->_data;
}

std::map<std::string, float> BitcoinExchange::_readFile(std::string const &filename) {
    std::map<std::string, float> data;
    if (!tryOpenFile(filename))
        return data;
    std::ifstream file(filename);
    std::string date;
    std::string strValue;
    float value;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        if (!validDate(date))
            continue;
        ss >> strValue;
        if (!validValue(strValue))
            continue;
        value = stringToFloat(strValue);
        data[date] = value;
    }
    return data;
}

float BitcoinExchange::getValue(std::string const &date) const {
    std::map<std::string, float>::const_iterator it = this->_data.find(date);
    // look for lower bound
    if (it == this->_data.end()) {
        std::map<std::string, float>::const_iterator it2 = this->_data.lower_bound(date);
        if (it2 == this->_data.begin()) {
            std::cout << COLOR("Error: date not found", RED) << std::endl;
            return -1;
        }
        it2--;
        return it2->second;
    }
    return it->second;
}

void BitcoinExchange::evaluateDataInput(std::string const &filename) {
    // look for the data within the file, get the value after the separator " | ", multiply it by the getValue() of the date and print the result
    std::fstream file(filename);
    std::string line;
    std::string date;
    std::string strValue;
    float value;
    float result;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, ' ');
        if (!validDate(date))
            continue;
        char c;
        ss >> c;
        if (c != '|')
            continue;
        // ss.ignore(2);

        ss >> strValue;
        if (ss.fail()) {
            std::cout << COLOR("Error: bad input => ", RED) << date << std::endl;
            continue;
        }
        value = stringToFloat(strValue);
        if (!validValue(strValue)) {
            printErrorValueMsg(value);
            continue;
        }
        float valueOnDate = getValue(date);
        if (valueOnDate < 0) {
            continue;
        }
        result = value * getValue(date);
        std::cout << date << " => " << value << " = " << result << " valueOnDate: " << valueOnDate << std::endl;
    }

}

void BitcoinExchange::printData(std::map<std::string, float> const &data) const {
    for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                MY FUNCTIONS                                */
/* -------------------------------------------------------------------------- */

bool tryOpenFile(std::string const &str) {
    std::ifstream file(str);
    if (!file.is_open()) {
        std::cout << COLOR("Error: cannot open file", RED) << std::endl;
        return false;
    }
    return true;
}

void printFile(std::string const &file) {
    std::ifstream ifs(file);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    std::cout << content << std::endl;
}

bool validDate(std::string const &str) {
    if (str.length() != 10)
        return false;
    if (str[4] != '-' || str[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool validValue(std::string const &str) {
    for (int i = 0; i < static_cast<int>(str.length()); i++) {
        if (str[i] == '.')
            continue;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    float value = std::atof(str.c_str());
    if (value < 0 || value > 1000)
        return false;
    return true;
}

void printErrorValueMsg(float value) {
    if (value < 0) {
        std::cout << COLOR("Error: not a positive number", RED) << std::endl;
    } else if (value > 1000) {
        std::cout << COLOR("Error: too large a number", RED) << std::endl;
    } else {
        std::cout << COLOR("Error: value not valid", RED) << std::endl;
    }
}

float stringToFloat(std::string const &str) {
    float value = std::atof(str.c_str());
    return value;
}
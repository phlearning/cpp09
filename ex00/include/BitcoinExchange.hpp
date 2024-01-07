/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:26 by pvong             #+#    #+#             */
/*   Updated: 2024/01/07 22:55:47 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <algorithm>
# include <map>

#ifndef SHOWMSG
#define SHOWMSG 0
#endif /* SHOWMSG */

#ifndef MYCOLORS
#define MYCOLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#define MSG_SEP "============================"
#define MSG_SEP2 "============="
#define COLOR(text, color) color << text << RESET
#define MY_SEP() std::cout << COLOR(MSG_SEP, BOLDBLACK) << std::endl
#define MY_SEP2(msg) std::cout << COLOR(MSG_SEP2, BOLDWHITE) << " " << msg << " " << COLOR(MSG_SEP2, BOLDWHITE) << std::endl

#endif /* MYCOLORS */

class BitcoinExchange {

public:
    // Canonical Form
    BitcoinExchange(BitcoinExchange const &src);
    ~BitcoinExchange(void);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    // My Constructor
    BitcoinExchange(std::string const &filename);

    // Getters
    std::string getFilename(void) const;
    std::map<std::string, float> getData(void) const;
    float getValue(std::string const &date) const;
    
    void printData(std::map<std::string, float> const &data) const;
    void evaluateDataInput(std::string const &filename);

private:
    BitcoinExchange(void); // Default constructor
    std::string _filename;
    std::map<std::string, float> _data;

    std::map<std::string, float> _readFile(std::string const &filename);
    
};

bool tryOpenFile(std::string const &str);
void printFile(std::string const &str);
bool validDateFormat(std::string const &str);
bool validDate(std::string const &str);
bool validValue(std::string const &str);
void printErrorValueMsg(float value);
float stringToFloat(std::string const &str);

#endif
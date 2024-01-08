/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:16:45 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 15:04:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

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

#define COLOR(text, color) color << text << RESET

#endif /* MYCOLORS */

#define K 5 // number of sub-elements to sort with insertion sort

void insertionSortVector(std::vector<int> &A, int p, int q);
void mergeVector(std::vector<int> &A, int p, int q, int r);
void mergeInsertionSortVector(std::vector<int> &A, int p, int r);

void insertionSortList(std::list<int> &A, int p, int q);
// void insertionSortList(std::list<int> &lst);
void mergeList(std::list<int> &A, int p, int q, int r);
void mergeInsertionSortList(std::list<int> &A, int p, int r);

void PmergeMe(int ac, char **av);

#endif
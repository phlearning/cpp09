/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:16:45 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 02:41:25 by pvong            ###   ########.fr       */
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

#define K 5 // number of sub-elements to sort with insertion sort

void insertionSortVector(std::vector<int> &A, int p, int q);
void mergeVector(std::vector<int> &A, int p, int q, int r);
void mergeInsertionSortVector(std::vector<int> &A, int p, int r);

void insertionSortList(std::list<int> &A, int p, int q);
void mergeList(std::list<int> &A, int p, int q, int r);
void mergeInsertionSortList(std::list<int> &A, int p, int r);

void PmergeMe(int ac, char **av);

#endif
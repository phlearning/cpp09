/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:17:44 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 02:01:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void PmergeMe(int ac, char **av) {

//     std::vector<int> v;
//     std::list<int> l;
//     std::vector<int>::iterator itv;
//     std::list<int>::iterator itl;

//     for (int i = 1; i < ac; i++) {
//         int nb = atoi(av[i]);
//         v.push_back(nb);
//         l.push_back(nb);
//     }

//     std::cout << "Vector:" << std::endl;
//     for (itv = v.begin(); itv != v.end(); itv++)
//         std::cout << *itv << " ";
//     std::cout << std::endl;
//     std::cout << "List:" << std::endl;
//     for (itl = l.begin(); itl != l.end(); itl++)
//         std::cout << *itl << " ";
//     std::cout << std::endl;

//     std::cout << "Vector:" << std::endl;
//     mergeInsertionSortVector(v, 0, v.size() - 1);
//     for (itv = v.begin(); itv != v.end(); itv++)
//         std::cout << *itv << " ";
//     std::cout << std::endl;
//     std::cout << "List:" << std::endl;
//     mergeInsertionSortList(l, 0, l.size() - 1);
//     for (itl = l.begin(); itl != l.end(); itl++)
//         std::cout << *itl << " ";
//     std::cout << std::endl;
// }
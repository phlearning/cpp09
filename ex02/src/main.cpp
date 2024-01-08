/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:15:37 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 01:55:10 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int main(int ac, char **av) {
//     if (ac < 2) {
//         std::cout << "Usage: ./PmergeMe [nb] [nb] ..." << std::endl;
//         return (1);
//     }
//     for (int i = 1; i < ac; i++) {
//             for (int j = 0; av[i][j]; j++) {
//                 if (!isdigit(av[i][j])) {
//                     std::cout << "Error: bad input." << std::endl;
//                     return (1);
//                 }
//             }
//             int nb = atoi(av[i]);
//             if (nb < 0) {
//                 std::cout << "Error: negative number." << std::endl;
//                 return (1);
//             }
//         }
//     PmergeMe(ac, av);
//     return (0);
// }
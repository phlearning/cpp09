/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:02 by pvong             #+#    #+#             */
/*   Updated: 2024/01/07 22:02:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << COLOR("Error: could not open file.", RED) << std::endl;
        return (0);
    }
    BitcoinExchange b(av[1]);
    b.evaluateDataInput(av[1]);

    return (0);
}
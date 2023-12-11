/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:02 by pvong             #+#    #+#             */
/*   Updated: 2023/12/11 16:39:22 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void) {

    BitcoinExchange b("input.txt");
    BitcoinExchange c(b);
    b.evaluateDataInput("input.txt");

    return (0);
}
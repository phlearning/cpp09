/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:36:19 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 00:10:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// (3 × 4) + (5 × 6) becomes 3 4 × 5 6 × + in reverse Polish notation. 
void rpn(std::string str) {
    std::stack<int> nb;
    std::stringstream ss(str);
    std::string token;
    int a;
    int b;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (nb.size() < 2) {
                std::cout << "Error: not enough values in stack." << std::endl;
                return;
            }
            a = nb.top();
            nb.pop();
            b = nb.top();
            nb.pop();
            if (token == "+")
                nb.push(b + a);
            else if (token == "-")
                nb.push(b - a);
            else if (token == "*")
                nb.push(b * a);
            else if (token == "/") {
                if (a == 0) {
                    std::cout << "Error: division by zero." << std::endl;
                    return;
                }
                nb.push(b / a);
            }
        } else {
            if (token.length() > 1 || !isdigit(token[0])) {
                std::cout << "Error: invalid token." << std::endl;
                return;
            }
            nb.push(atoi(token.c_str()));
        }
    }
    if (nb.size() != 1) {
        std::cout << "Error: too many values in stack." << std::endl;
        return;
    }
    std::cout << nb.top() << std::endl;
}
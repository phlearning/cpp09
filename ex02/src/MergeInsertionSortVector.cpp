/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertionSortVector.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:34:35 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 16:05:48 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void insertionSortVector(std::vector<int> &A, int p, int q) {
//     for (int i = p; i < q; i++) {
//         int tmp = A[i + 1];
//         int j = i + 1;
//         while (j > p && A[j - 1] > tmp) {
//             A[j] = A[j - 1];
//             j--;
//         }
//         A[j] = tmp;
//     }
// }


// void mergeVector(std::vector<int> &A, int p, int q, int r) {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     std::vector<int> L;
//     std::vector<int> R;
//     for (int i = 0; i < n1; i++)
//         L.push_back(A[p + i]);
//     for (int j = 0; j < n2; j++)
//         R.push_back(A[q + j + 1]);
//     int Rindex = 0;
//     int Lindex = 0;
//     for (int i = p; i <= r; i++) {
//         if (Rindex >= n2 || (Lindex < n1 && L[Lindex] <= R[Rindex])) {
//             A[i] = L[Lindex];
//             Lindex++;
//         }
//         else {
//             A[i] = R[Rindex];
//             Rindex++;
//         }
//     }
// }

// void mergeInsertionSortVector(std::vector<int> &A, int p, int r) {
//     if (r - p > K) {
//         int q = (p + r) / 2;
//         mergeInsertionSortVector(A, p, q);
//         mergeInsertionSortVector(A, q + 1, r);
//         mergeVector(A, p, q, r);
//     }
//     else
//         insertionSortVector(A, p, r);
// }

// int main() {
//     std::vector<int> A;
//     A.push_back(5);
//     A.push_back(3);
//     A.push_back(9);
//     A.push_back(2);
//     A.push_back(8);
//     A.push_back(7);
//     A.push_back(1);
//     A.push_back(4);
//     A.push_back(6);
//     int n = A.size();
//     mergeInsertionSortVector(A, 0, n - 1);
//     for (int i = 0; i < n; i++) {
//         std::cout << A[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

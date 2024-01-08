/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertionSortList.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 02:20:42 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 16:05:59 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// // void insertionSortList(std::list<int> &A, int p, int q) {
// //     std::list<int>::iterator it = A.begin();
// //     std::advance(it, p);
// //     for (int j = p + 1; j <= q; j++) {
// //         std::list<int>::iterator next = it;
// //         std::advance(next, 1);
// //         int key = *next;
// //         std::list<int>::iterator it2 = it;
// //         int i = j - 1;
// //         while (i >= p && *it2 > key) {
// //             std::list<int>::iterator next2 = it2;
// //             std::advance(next2, 1);
// //             *next2 = *it2;
// //             if (it2 != A.begin()) {
// //                 it2--;
// //             }
// //             i--;
// //         }
// //         std::list<int>::iterator next2 = it2;
// //         std::advance(next2, 1);
// //         *next2 = key;
// //         it++;
// //     }
// // }

// // void insertionSortList(std::list<int> &lst) {
// //     if (lst.size() <= 1) return; // List is already sorted

// //     for (std::list<int>::iterator i = ++lst.begin(); i != lst.end(); ++i) {
// //         std::list<int>::iterator j = i;
// //         std::list<int>::iterator insertion = i;
// //         insertion--;
// //         while (j != lst.begin() && *insertion > *i) {
// //             j--;
// //             if (j != lst.begin()) {
// //                 insertion--;
// //             }
// //         }
// //         if (j != i) {
// //             int temp = *i;
// //             lst.erase(i);
// //             lst.insert(j, temp);
// //             i = j;
// //         }
// //     }
// // }

// void insertionSortList(std::list<int>& lst, int p, int q) {
//     if (q <= p || lst.size() <= 1) return; // Subarray is already sorted

//     std::list<int>::iterator start = lst.begin();
//     std::advance(start, p);

//     std::list<int>::iterator end = lst.begin();
//     std::advance(end, q);

//     for (std::list<int>::iterator i = start; i != end; ++i) {
//         for (std::list<int>::iterator j = i; j != start; --j) {
//             std::list<int>::iterator prev = j;
//             --prev;
//             if (*j < *prev) {
//                 int temp = *j;
//                 *j = *prev;
//                 *prev = temp;
//             } else {
//                 break;
//             }
//         }
//     }
// }


// // void mergeList(std::list<int> &A, int p, int q, int r) {
// //     int n1 = q - p + 1;
// //     int n2 = r - q;
// //     std::list<int> LA, RA;
// //     std::list<int>::iterator it = A.begin();
// //     std::advance(it, p);
// //     for (int i = 0; i < n1; i++) {
// //         LA.push_back(*it);
// //         it++;
// //     }
// //     for (int i = 0; i < n2; i++) {
// //         RA.push_back(*it);
// //         it++;
// //     }
// //     int RIDX = 0;
// //     int LIDX = 0;
// //     it = A.begin();
// //     std::advance(it, p);
// //     for (int i = p; i <= r; i++) {
// //         if (RIDX == n2) {
// //             *it = LA.front();
// //             LA.pop_front();
// //             LIDX++;
// //         } else if (LIDX == n1) {
// //             *it = RA.front();
// //             RA.pop_front();
// //             RIDX++;
// //         } else if (RA.front() > LA.front()) {
// //             *it = LA.front();
// //             LA.pop_front();
// //             LIDX++;
// //         } else {
// //             *it = RA.front();
// //             RA.pop_front();
// //             RIDX++;
// //         }
// //         it++;
// //     }
// // }

// void mergeList(std::list<int> &A, int p, int q, int r) {
//     std::list<int> left, right;

//     std::list<int>::iterator it = A.begin();
//     std::advance(it, p);

//     for (int i = p; i <= q; i++) {
//         left.push_back(*it);
//         it++;
//     }

//     for (int i = q + 1; i <= r; i++) {
//         right.push_back(*it);
//         it++;
//     }

//     it = A.begin();
//     std::advance(it, p);

//     while (!left.empty() && !right.empty()) {
//         if (left.front() <= right.front()) {
//             *it = left.front();
//             left.pop_front();
//         } else {
//             *it = right.front();
//             right.pop_front();
//         }
//         it++;
//     }

//     while (!left.empty()) {
//         *it = left.front();
//         left.pop_front();
//         it++;
//     }

//     while (!right.empty()) {
//         *it = right.front();
//         right.pop_front();
//         it++;
//     }
// }

// // void mergeList(std::list<int> &A, int p, int q, int r) {
// //     int n1 = q - p + 1;
// //     int n2 = r - q;
// //     std::list<int> L, R;
// //     std::list<int>::iterator it = A.begin();
// //     std::advance(it, p);
// //     for (int i = 0; i < n1; i++) {
// //         L.push_back(*it);
// //         it++;
// //     }
// //     for (int j = 0; j < n2; j++) {
// //         R.push_back(*it);
// //         it++;
// //     }
// //     int Rindex = 0;
// //     int Lindex = 0;
// //     it = A.begin();
// //     std::advance(it, p);
// //     for (int i = p; i <= r; i++) {
// //         if (Rindex >= n2 || (Lindex < n1 && L.front() <= R.front())) {
// //             *it = L.front();
// //             L.pop_front();
// //             Lindex++;
// //         } else {
// //             *it = R.front();
// //             R.pop_front();
// //             Rindex++;
// //         }
// //         it++;
// //     }
// // }

// void mergeInsertionSortList(std::list<int> &A, int p, int r) {
//     if (r - p > K) {
//         int q = (p + r) / 2;
//         mergeInsertionSortList(A, p, q);
//         mergeInsertionSortList(A, q + 1, r);
//         mergeList(A, p, q, r);
//     } else
//         insertionSortList(A, p, r + 1);
// }

// // int main() {
// //     std::list<int> A;
// //     A.push_back(3);
// //     A.push_back(5);
// //     A.push_back(9);
// //     A.push_back(7);
// //     A.push_back(4);
// //     // A.push_back(3);
// //     std::cout << "Before:" << std::endl;
// //     for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
// //         std::cout << *it << " ";
// //     std::cout << std::endl;
// //     int n = A.size();
// //     mergeInsertionSortList(A, 0, n - 1);
// //     // insertionSortLst(A, 0, K);
// //     // mergeLst(A, 0, K, A.size()-1);
// //     std::cout << "After:" << std::endl;
// //     for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
// //         std::cout << *it << " ";
// //     std::cout << std::endl;
// //     return 0;
// // }
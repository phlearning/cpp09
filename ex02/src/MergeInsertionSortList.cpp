/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertionSortList.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 02:20:42 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 03:19:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void insertionSortList(std::list<int> &A, int p, int q) {
    std::list<int>::iterator it = A.begin();
    std::advance(it, p);
    for (int i = p; i < q; i++) {
        std::advance(it, 1);
        int tmp = *it;
        int j = i + 1;
        std::list<int>::iterator it2 = A.begin();
        std::advance(it2, j - 1);
        while (j > p && *it2 > tmp) {
            it
        }
        // it2--;
        // while (it2 != A.begin() && *it2 > tmp) {
        //     *it = *it2;
        //     it--;
        //     it2--;
        // }
        // *it = tmp;
        // it = it2;
    }
}

void mergeList(std::list<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::list<int> LA, RA;
    std::list<int>::iterator it = A.begin();
    std::advance(it, p);
    for (int i = 0; i < n1; i++) {
        LA.push_back(*it);
        it++;
    }
    for (int i = 0; i < n2; i++) {
        RA.push_back(*it);
        it++;
    }
    int RIDX = 0;
    int LIDX = 0;
    it = A.begin();
    std::advance(it, p);
    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            *it = LA.front();
            LA.pop_front();
            LIDX++;
        } else if (LIDX == n1) {
            *it = RA.front();
            RA.pop_front();
            RIDX++;
        } else if (RA.front() > LA.front()) {
            *it = LA.front();
            LA.pop_front();
            LIDX++;
        } else {
            *it = RA.front();
            RA.pop_front();
            RIDX++;
        }
        it++;
    }
}

// void mergeList(std::list<int> &A, int p, int q, int r) {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     std::list<int> L, R;
//     std::list<int>::iterator it = A.begin();
//     std::advance(it, p);
//     for (int i = 0; i < n1; i++) {
//         L.push_back(*it);
//         it++;
//     }
//     for (int j = 0; j < n2; j++) {
//         R.push_back(*it);
//         it++;
//     }
//     int Rindex = 0;
//     int Lindex = 0;
//     it = A.begin();
//     std::advance(it, p);
//     for (int i = p; i <= r; i++) {
//         if (Rindex >= n2 || (Lindex < n1 && L.front() <= R.front())) {
//             *it = L.front();
//             L.pop_front();
//             Lindex++;
//         } else {
//             *it = R.front();
//             R.pop_front();
//             Rindex++;
//         }
//         it++;
//     }
// }

void mergeInsertionSortList(std::list<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertionSortList(A, p, q);
        mergeInsertionSortList(A, q + 1, r);
        mergeList(A, p, q, r);
    } else
        insertionSortList(A, p, r);
}

int main() {
    std::list<int> A;
    A.push_back(3);
    A.push_back(5);
    A.push_back(9);
    A.push_back(7);
    A.push_back(4);
    // A.push_back(3);
    int n = A.size();
    mergeInsertionSortList(A, 0, n - 1);
    // insertionSortLst(A, 0, K);
    // mergeLst(A, 0, K, A.size()-1);
    for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}
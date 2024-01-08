/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:17:44 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 16:05:36 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* -------------------------------------------------------------------------- */
/*                                  PMERGEME                                  */
/* -------------------------------------------------------------------------- */

void PmergeMe(int ac, char **av) {

    std::vector<int> v;
    std::list<int> l;
    std::vector<int>::iterator itv;
    std::list<int>::iterator itl;

    for (int i = 1; i < ac; i++) {
        int nb = atoi(av[i]);
        v.push_back(nb);
        l.push_back(nb);
    }
    
    std::cout << std::endl;
    std::cout << COLOR("Before:", CYAN) << " ";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;
    
    // Measure the time taken to sort the vector and display the vector sorted
    time_t start = clock();
    mergeInsertionSortVector(v, 0, v.size() - 1);
    time_t timeTaken = clock() - start;
    std::cout << COLOR("After Vector:", CYAN) << " ";
    for (itv = v.begin(); itv != v.end(); itv++)
        std::cout << *itv << " ";
    std::cout << std::endl;

    // Measure the time taken to sort the list and display the list sorted
    time_t start2 = clock();
    mergeInsertionSortList(l, 0, l.size() - 1);
    time_t timeTaken2 = clock() - start2;
    std::cout << COLOR("After List:", CYAN) << " ";
    for (itl = l.begin(); itl != l.end(); itl++)
        std::cout << *itl << " ";
    std::cout << std::endl;

    // Display the time taken in ms
    double dTimeTaken = static_cast<double>(timeTaken) * 1000 / CLOCKS_PER_SEC;
    double dTimeTaken2 = static_cast<double>(timeTaken2) * 1000 / CLOCKS_PER_SEC;
    std::cout << COLOR("Time to process a range of ", GREEN) << ac - 1 << COLOR(" elements with std::vector: ", GREEN)
        << std::fixed << std::setprecision(4) << dTimeTaken << " ms" << std::endl;
    std::cout << COLOR("Time to process a range of ", GREEN) << ac - 1 << COLOR(" elements with std::list: ", GREEN)
        << std::fixed << std::setprecision(4) << dTimeTaken2 << " ms" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                          MERGE INSERTION SORT LIST                         */
/* -------------------------------------------------------------------------- */

void insertionSortList(std::list<int>& lst, int p, int q) {
    if (q <= p || lst.size() <= 1) return; // Subarray is already sorted

    std::list<int>::iterator start = lst.begin();
    std::advance(start, p);

    std::list<int>::iterator end = lst.begin();
    std::advance(end, q);

    for (std::list<int>::iterator i = start; i != end; ++i) {
        for (std::list<int>::iterator j = i; j != start; --j) {
            std::list<int>::iterator prev = j;
            --prev;
            if (*j < *prev) {
                int temp = *j;
                *j = *prev;
                *prev = temp;
            } else {
                break;
            }
        }
    }
}

void mergeList(std::list<int> &A, int p, int q, int r) {
    std::list<int> left, right;

    std::list<int>::iterator it = A.begin();
    std::advance(it, p);

    for (int i = p; i <= q; i++) {
        left.push_back(*it);
        it++;
    }

    for (int i = q + 1; i <= r; i++) {
        right.push_back(*it);
        it++;
    }

    it = A.begin();
    std::advance(it, p);

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            *it = left.front();
            left.pop_front();
        } else {
            *it = right.front();
            right.pop_front();
        }
        it++;
    }

    while (!left.empty()) {
        *it = left.front();
        left.pop_front();
        it++;
    }

    while (!right.empty()) {
        *it = right.front();
        right.pop_front();
        it++;
    }
}

void mergeInsertionSortList(std::list<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertionSortList(A, p, q);
        mergeInsertionSortList(A, q + 1, r);
        mergeList(A, p, q, r);
    } else
        insertionSortList(A, p, r + 1);
}

/* -------------------------------------------------------------------------- */
/*                         MERGE INSERTION SORT VECTOR                        */
/* -------------------------------------------------------------------------- */

void insertionSortVector(std::vector<int> &A, int p, int q) {
    for (int i = p; i < q; i++) {
        int tmp = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tmp) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
    }
}


void mergeVector(std::vector<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> L;
    std::vector<int> R;
    for (int i = 0; i < n1; i++)
        L.push_back(A[p + i]);
    for (int j = 0; j < n2; j++)
        R.push_back(A[q + j + 1]);
    int Rindex = 0;
    int Lindex = 0;
    for (int i = p; i <= r; i++) {
        if (Rindex >= n2 || (Lindex < n1 && L[Lindex] <= R[Rindex])) {
            A[i] = L[Lindex];
            Lindex++;
        }
        else {
            A[i] = R[Rindex];
            Rindex++;
        }
    }
}

void mergeInsertionSortVector(std::vector<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertionSortVector(A, p, q);
        mergeInsertionSortVector(A, q + 1, r);
        mergeVector(A, p, q, r);
    }
    else
        insertionSortVector(A, p, r);
}
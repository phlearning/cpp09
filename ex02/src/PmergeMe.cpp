/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:17:44 by pvong             #+#    #+#             */
/*   Updated: 2024/01/08 16:45:33 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* -------------------------------------------------------------------------- */
/*                                  PMERGEME                                  */
/* -------------------------------------------------------------------------- */

/**
 * @brief Sorts a range of elements in a vector and a list using merge-insertion sort algorithm.
 * 
 * This function takes an array of strings as input and converts them to integers. It then populates
 * a vector and a list with these integers. The function measures the time taken to sort the vector
 * and the list using the merge-insertion sort algorithm. It then displays the sorted vector and list,
 * as well as the time taken to process the range of elements in milliseconds.
 * 
 * @param ac The number of elements in the array.
 * @param av The array of strings representing the elements.
 */
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

/**
 * Sorts a subarray of a list using the insertion sort algorithm.
 * 
 * @param lst The list to be sorted.
 * @param p The starting index of the subarray.
 * @param q The ending index of the subarray.
 */
void insertionSortList(std::list<int> &lst, int p, int q) {
    if (q <= p || lst.size() <= 1)
        return; // Subarray is already sorted

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

/**
 * Merges two sublists of a given list.
 * 
 * @param A The list to be merged.
 * @param p The starting index of the first sublist.
 * @param q The ending index of the first sublist.
 * @param r The ending index of the second sublist.
 */
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

/**
 * Sorts a sublist of a given list using merge sort and insertion sort.
 * 
 * @param A The list to be sorted.
 * @param p The starting index of the sublist.
 * @param r The ending index of the sublist.
 */
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


/**
 * Merges two subarrays of a vector.
 * n1 is the size of the first subarray.
 * n2 is the size of the second subarray.
 * 
 * Example of array A = {1, 3, 5, 2, 4, 6}:
 * p = 0, q = 2, r = 5
 * A[p..q] = {1, 3, 5} // A[0..2] = {1, 3, 5}
 * 
 * @param A The vector to be merged.
 * @param p The starting index of the first subarray.
 * @param q The ending index of the first subarray.
 * @param r The ending index of the second subarray.
 */
void mergeVector(std::vector<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    
    std::vector<int> L;
    for (int i = 0; i < n1; i++)
        L.push_back(A[p + i]);
    int Lindex = 0;

    std::vector<int> R;
    for (int j = 0; j < n2; j++)
        R.push_back(A[q + j + 1]);
    int Rindex = 0;

    for (int i = p; i <= r; i++) {
        // If Rindex >= n2, then R is empty, or if Lindex < n1 and L[Lindex] <= R[Rindex], then L[Lindex] is the next smallest element
        // Otherwise, R[Rindex] is the next smallest element
        // A[i] is set to the next smallest element
        if (Rindex >= n2 || (Lindex < n1 && L[Lindex] <= R[Rindex])) {
            A[i] = L[Lindex];
            Lindex++;
        } else {
            A[i] = R[Rindex];
            Rindex++;
        }
    }
}


/**
 * Recursively sorts a vector using merge sort algorithm for larger subarrays and insertion sort algorithm for smaller subarrays.
 * 
 * @param A The vector to be sorted.
 * @param p The starting index of the subarray to be sorted.
 * @param r The ending index of the subarray to be sorted.
 */
void mergeInsertionSortVector(std::vector<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertionSortVector(A, p, q);
        mergeInsertionSortVector(A, q + 1, r);
        mergeVector(A, p, q, r);
    } else
        insertionSortVector(A, p, r);
}

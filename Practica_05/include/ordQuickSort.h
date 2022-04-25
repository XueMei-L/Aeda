#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class QuickSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        QuickSort();
        ~QuickSort();
        // Hay que implementarlo en la subclase
        std::vector<Key> sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
QuickSort<Key>::QuickSort() {}

template<class Key>
QuickSort<Key>::~QuickSort() {}

template<class Key>
std::vector<Key> QuickSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de QuickSort...\n";
    // ordenacionQuickSort(seq, 0, a);
    return seq;
}

#endif //QUICKSORT_H
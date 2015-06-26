#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

namespace quick_sort {

  class quick_sort
  {
   public:
    template<typename T> static void quickSort(std::vector<T> &list,
                                               int start = 0, int end = 0);
  };
}

#include "quick_sort.tpp"

#endif

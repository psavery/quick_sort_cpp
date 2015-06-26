#ifndef RANDOM_H
#define RANDOM_H

#include <vector>

class rng
{
 public:
  static std::vector<int> generateRandomIntVector(int size, int low,
                                                  int high);
};


#endif

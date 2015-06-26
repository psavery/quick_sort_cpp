#include <iostream>
#include <fstream>

#include "quick_sort.h"
#include "rng.h"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "\nInvalid number of arguments.\n";
    std::cout << "Please enter arguments for:\n1. Size of the list to be " <<
                 "generated.\n2. Smallest number to be generated.\n3." <<
                 " Largest number to be generated.\nRespectively.";
    return 1;
  }

  std::vector<int> list = rng::rng::generateRandomIntVector(
                            atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

  // Print unsorted list to terminal and write output file...
  std::cout << "\nUNSORTED:\n";

  std::ofstream myfile;
  myfile.open("generatedLists.txt");
  myfile << "UNSORTED:\n";

  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list[i] << std::endl;
    myfile << list[i] << std::endl;
  }

  // Sort. quickSort() accepts an alias of std::vector<T>
  quick_sort::quick_sort::quickSort(list);

  // Print sorted list to terminal and output file...
  std::cout << "\nSORTED:\n";
  myfile << "\nSORTED:\n";

  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list[i] << std::endl;
    myfile << list[i] << std::endl;
  }

  myfile.close();
}


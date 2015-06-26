#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

#include "quick_sort.h"
#include "rng.h"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "\nInvalid number of arguments.\n";
    std::cout << "Please enter arguments for:\n1. Size of the list to be " <<
                 "generated.\n2. Smallest number to be generated.\n3." <<
                 " Largest number to be generated.\nRespectively.\n";
    return 1;
  }

  std::vector<int> list = rng::rng::generateRandomIntVector(
                            atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

  // This will be used to compare to std::sort()
  std::vector<int> list2 = list;

  // Print unsorted list to output file...
  std::ofstream myfile;
  myfile.open("generatedLists.txt");
  myfile << "UNSORTED:\n";

  for (size_t i = 0; i < list.size(); i++) {
    myfile << list[i] << std::endl;
  }

  // Sort. quickSort() accepts an alias of std::vector<T>
  // start is CPU time. start2 is wall time.
  std::clock_t start = clock();
  auto start2 = std::chrono::high_resolution_clock::now();

  quick_sort::quick_sort::quickSort(list);

  auto cpuTime = (clock() - start) / (double) CLOCKS_PER_SEC;
  auto wallTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start2).count() * 0.001;

  // Print sorted list to output file...
  myfile << "\nSORTED:\n";

  for (size_t i = 0; i < list.size(); i++) {
    myfile << list[i] << std::endl;
  }

  std::cout << "\nCPU TIME:\n" << cpuTime << "\n\n";
  std::cout << "\nWALL TIME:\n" << wallTime << "\n\n";

  myfile << "\nCPU TIME:\n" << cpuTime << "\n\n";
  myfile << "\nWALL TIME:\n" << wallTime << "\n\n";

  start = clock();
  start2 = std::chrono::high_resolution_clock::now();

  std::sort(list2.begin(), list2.end());

  cpuTime = (clock() - start) / (double) CLOCKS_PER_SEC;
  wallTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start2).count() * 0.001;

  std::cout << "\nBUILT-IN SORT CPU TIME:\n" << cpuTime << "\n\n";
  std::cout << "\nBUILT-IN SORT WALL TIME:\n" << wallTime << "\n\n";

  myfile << "\nBUILT-IN SORT CPU TIME:\n" << cpuTime << "\n\n";
  myfile << "\nBUILT-IN SORT WALL TIME:\n" << wallTime << "\n\n";

  myfile.close();
}

PROGRAM = quickSort
PROGSRC = main.cpp rng.cpp quick_sort.h
CXXFLAGS = -O3 -std=c++11
#CXX = icpc
#CXXLIBS = -mkl
OBJECTS = $(PROGSRC:%.cc=%.o)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: $.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(PROGRAM) *.o

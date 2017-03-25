CXXFLAGES = -std=c++11

all: executable

debug: CXXFLAGES += -g
debug: executable

rebuild:clean executable

executable: main.o
	$(CXX) $(CXXFLAGS) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

clean:
	rm -f *.o a.out

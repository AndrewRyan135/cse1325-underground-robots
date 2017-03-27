
CXXFLAGS = -std=c++11 


all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild:clean executable


executable: main.o customer.o catologe.o sales_associate.o #robot.o
	$(CXX) $(CXXFLAGS) main.o customer.o catologe.o sales_associate.o


customer.o: customer.cpp customer.h
	$(CXX) $(CXXFLAGS) -c customer.cpp

sales_associate.o: sales_associate.cpp sales_associate.h
	$(CXX) $(CXXFLAGS) -c sales_associate.cpp

catologe.o: catologe.cpp catologe.h
	$(CXX) $(CXXFLAGS) -c catologe.cpp

robot.o: robot.cpp robot.h
	$(CXX) $(CXXFLAGS) -c robot.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

clean:
	rm -f *.o a.out

#layout for this make file:
#if you want to add a header and .cpp to link against main, for example: file.cpp and file.h
#
#
#between "executable:" and "main.o:", add
#
#excuteable:
#
#file.o: file.cpp file.h
#	$(CXX) $(CXXFLAGS) -c file.cpp
#
#main.o:
#---------------------------------------------
#
#After that, update the "executable:" section like
#
#executable: main.o filename.o
#	$(CXX) $(CXXFLAGS) main.o filename.o
#
#---------------------------------------------
#
#Do this process everytime you add a new .cpp and .h




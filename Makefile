#Makefile design adapted for use on this project from example given by Manzillo on stackoverflow.com, URL: http://stackoverflow.com/questions/231229/how-to-generate-a-makefile-with-source-in-sub-directories-using-just-one-makefil
CXXFLAGS = -std=c++11
CC		  := g++ 'fltk-config --cxxflags'
LD		  := g++ 'fltk-config --use-images --cxxflags' -L/usr/local/lib -lfltk -lXext -lX11 -lm

MODULES   := store robot store_associates
SRC_DIR   := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES))

SRC 	  := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ		  := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@
endef

#PHONY declares keywords will never be files
.PHONY: all checkdirs clean

#all: executable
all: checkdirs build/demo

build/demo: $(OBJ)
	$(LD) $^ -o $@

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

#debug: CXXFLAGS += -g
#debug: executable

#rebuild:clean executable


#executable: main.o customer.o  sales_associate.o robot.o order.o catalog.o
	#$(CXX) $(CXXFLAGS) main.o customer.o sales_associate.o robot.o order.o catalog.o


#customer.o: customer.cpp customer.h
	#$(CXX) $(CXXFLAGS) -c customer.cpp

#sales_associate.o: sales_associate.cpp sales_associate.h
	#$(CXX) $(CXXFLAGS) -c sales_associate.cpp

#catalog.o: catalog.cpp catalog.h
	#$(CXX) $(CXXFLAGS) -c catalog.cpp

#robot.o: robot.cpp robot.h
	#$(CXX) $(CXXFLAGS) -c robot.cpp

#order.o: order.cpp order.h
	#$(CXX) $(CXXFLAGS) -c order.cpp

#main.o: main.cpp
	#$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

#clean:
	#rm -f *.o *.h.gch a.out

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




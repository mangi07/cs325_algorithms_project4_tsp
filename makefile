
CXX = g++
CXXFLAGS = -std=c++0x -g
#OBJS = 
HEADERS = MST_PRIM.h MATCH.h cities.h

default:  main.cpp cities.o ${HEADERS}
	${CXX} ${CXXFLAGS} main.cpp cities.o ${HEADERS} -o tsp


	
cities.o: cities.cpp cities.h
	g++ -std=c++0x -g cities.cpp cities.h -c
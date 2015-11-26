


default: main.cpp cities.h cities.cpp
	g++ -std=c++0x main.cpp cities.cpp -o tsp
	
debug: main.cpp cities.h cities.cpp
	g++ -std=c++0x -g main.cpp cities.cpp -o tsp
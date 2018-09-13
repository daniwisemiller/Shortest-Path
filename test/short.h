#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>

using namespace std;

class test
{
public:
	
	
private:
	int cases;
	int cities;
	string city1;
	string city2;
	string city3;
	string city4;
    int graph[4][4] = {{0, 1, 2, 0,},
                       {1, 0, 5, 6,},
                       {2, 5, 0, 7,},
                       {0, 6, 7, 0,},
                       };
};
#endif
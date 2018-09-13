/***********************
Danielle Wisemiller
11/28/2016
Project 6 - Shortest Path
************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include "short.h"

using namespace std;

int SIZE;
vector<string> allcityNames;

//calculate min distance 
int minDistance(int dist[], bool visit[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < SIZE; v++)
   	{
   	     if (visit[v] == false && dist[v] <= min)
		 {
		 	min = dist[v], min_index = v;
		 }
   	}
   return min_index;
}

void printSolution(int prev[SIZE], int dist[SIZE])
{
   vector<int> pindex;
   int temp = SIZE-1;
   while(temp!=0)
   {
	   pindex.insert(pindex.begin(), temp);
	   temp = prev[temp];
   }
   
   pindex.insert(pindex.begin(), temp);
   
   //print array values
   for(int i=0; i<pindex.size(); i++)
   {
	   cout<<allcityNames[pindex[i]]<< " ";
   }
   cout<<dist[SIZE-1]<<endl;
}

void dijkstra(vector < vector <int> > graph, int source)
{
     int dist[SIZE];   
     bool visit[SIZE]; 
	 int prev[SIZE];
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < SIZE; i++)
	 {
	 	dist[i] = INT_MAX;
	 	visit[i] = false;
		prev[i] = -1;
	 }
     dist[source] = 0;
  
     //find shortest path for all vertices
     for (int count = 0; count < SIZE-1; count++)
     {
		 int u = minDistance(dist, visit);
		 if(u == SIZE-1)
			 break;
		 visit[u] = true;
  
       // Update dist value 
       for (int v = 0; v < SIZE; v++)
         if ((visit[v]==false) && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
	   		{
	   	   	 	dist[v] = dist[u] + graph[u][v];
		   	 	prev[v] = u;
	  	  	}
     }
     //print array
     printSolution(prev, dist);
}
/**************************************************MAIN**************************************************/
int main()
{
	int cases;
	cin>>cases;
	
	for(int i=0; i<cases; i++)
	{
		int cityNums = 0;
		cin>>cityNums;
		SIZE = cityNums;
		
		vector<string>cities;
		string temp;
		for(int j=0; j< cityNums; j++)
		{
			cin>>temp;
			cities.push_back(temp);
		}
		
		allcityNames = cities;
		
		vector< vector <int> > nums;
		nums.resize(SIZE);
		for(int k=0; k<SIZE; k++)
		{
			nums[k].resize(cityNums);
		}
		
		for(int l=0; l<cityNums; l++)
		{
			for(int m=0; m<cityNums; m++)
			{
				cin>>nums[l][m];
			}
		}	
		dijkstra(nums, 0);
	}
}



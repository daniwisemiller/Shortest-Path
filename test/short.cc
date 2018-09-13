
  
#include <iostream>  
//vertices
#define V 6

using namespace std;
  
//find the vertex with minimum distance value, 
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   cout<<"Vertex   Distance from Source\n";
   for (int i = 0; i < V; i++)
      cout<<i<<"          "<<dist[i]<<endl;
}
  
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     //output array - dist[i] will hold the shortest distance from src to i
  
     bool sptSet[V]; // sptSet[i] = true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is final
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Picks the min distance vertex from the set of vertices not
		 //traveled to yet. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}
  
// driver program to test above function
int main()
{
    int graph[V][V] = {{0, 3, 15, 4, 0, 0,},
                       {3, 0, 5, 0, 8, 12,},
                       {15, 5, 0, 0, 2, 0,},
                       {4, 0, 0, 0, 0, 7,},
					   {0, 8, 2, 0, 0, 0,},
					   {0, 12, 0, 7, 0, 0}
                       };
    dijkstra(graph, 0);
  
    return 0;
}
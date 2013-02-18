#include <iostream>
using namespace std;
#define V 9
void dijkstra(int graph[][V], int src){
	int dist[V];
	bool sptset[V];
	for(int i =0; i < V;i++){
		dist[i] = INT_MAX;
		sptset[i] = false;
	}
	dist[src] = 0;
	for(int count = 1; count < V;count++){
		//pick the min one
		int min = INT_MAX;
		int u = 0;
		for(int i = 0;i< V;i++){
			if(!sptset[i] && min > dist[i]){
				u = i;
				min = dist[i];
			}
		}
		sptset[u] = true;
		for(int i = 0 ; i < V;i++){
			if(!sptset[i] && graph[u][i] && dist[u] + graph[u][i] < dist[i])
				dist[i] = dist[u] + graph[u][i]; 
		}
	}

	for(int i =0 ;i < V;i++)
		cout<<i<<"    "<<dist[i]<<endl;
}
int dijmain()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {0, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
	return 0;
}
 
  
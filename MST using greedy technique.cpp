#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100  
int minKey(int key[], int mstSet[], int n) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < n; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;
   return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n) {
   int parent[n];  
   int key[n];     
   int mstSet[n]; 

   for (int i = 0; i < n; i++)
      key[i] = INT_MAX, mstSet[i] = 0;

   key[0] = 0;
   parent[0] = -1;  // first node is always root of MST

   // construct MST with (n-1) edges
   for (int count = 0; count < n - 1; count++) {
      // pick the minimum key vertex from the set of vertices not yet included in MST
      int u = minKey(key, mstSet, n);

      // add the picked vertex to the MST set
      mstSet[u] = 1;

      // update key value and parent index of adjacent vertices of the picked vertex.
      // consider only those vertices which are not yet included in MST
      for (int v = 0; v < n; v++)
         if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
   }

   // print the constructed MST
   printMST(parent, graph, n);
}

int main() {
   int graph[V][V], n,w;

   printf("Enter the number of vertices in the graph (<= %d): ", V);
   scanf("%d", &n);

   printf("Enter the adjacency matrix of the graph:\n");
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         scanf("%d", &graph[i][j]);
         w=(i+j);
   primMST(graph, n,w);

   return 0;
}


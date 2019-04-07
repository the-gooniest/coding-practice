#include <stdio.h>
#include <limits.h>
#include "BinaryHeap.h"
#include <stack>

#define V 6

using namespace std;

int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printSolution(int dist[], int predecessor[])
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
	int index = V - 1;
	printf("path: ");
	while (index != -1) {
		printf("%d ", index);
		index = predecessor[index];
	}
	printf("\n");
}

void dijkstra(int graph[V][V], int source) {
	int dist[V];
	bool sptSet[V];
	int predecessor[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
		predecessor[i] = -1;
	}

	dist[source] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for (int v = 0; v < V; v++) {
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
				predecessor[v] = u;
			}
		}
	}
	printSolution(dist, predecessor);
}

int main() {
	/* int graph[V][V] = {
		{ 0, 1, 2, 0, 0, 0 },
		{ 1, 0, 0, 4, 4, 0 },
		{ 2, 0, 0, 3, 4, 0 },
		{ 0, 4, 3, 0, 0, 2 },
		{ 0, 4, 4, 0, 0, 1 },
		{ 0, 0, 0, 2, 1, 0 }
	};
	dijkstra(graph, 0); */

	BinaryHeap<int> heap;
	for (int i = 0; i < 100; i++)
		heap.insertKey(i), printf("%d %d\n", i, heap.capacity());
	heap.print();

	return 0;
}
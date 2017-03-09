#include<iostream>
#define SIZE 9
using namespace std;

void dijkstra(int(*G)[SIZE], int s);
int findMinIndex(int *d, bool *visited);
void printSolution(int *d);

int main() {
	int graph[SIZE][SIZE] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
						};

	dijkstra(graph, 0);
	system("pause");
}

/*
	Find the vertex that is not visited and whose distance at the moment is minimum.
	Relax all edges coming out from the vertex. 
	Conditions would be: 1. There is an edge. 2. The newly computed distance is shorter than the previous d[i]
	Loop through all vertices using the priority queue, then the d[i] stores the minimum distance from source to vertex i.
*/
void dijkstra(int(*G)[SIZE], int s) {
	bool visited[SIZE];
	int d[SIZE];
	for (int i = 0; i < SIZE; i++) {
		visited[i] = false;
		d[i] = INT_MAX;
	}
	d[s] = 0;
	int minIndex = -1;
	while ((minIndex = findMinIndex(d, visited)) != -1)
	{
		visited[minIndex] = true;
		for (int i = 0; i < SIZE; i++) {
			if (G[minIndex][i]&&d[i] > d[minIndex] + G[minIndex][i]) {
				d[i] = d[minIndex] + G[minIndex][i];
			}
		}
	}
	printSolution(d);
}

//Acts as a priority queue, each time extract the minimum distance to investigate
int findMinIndex(int *d, bool *visited) {
	int minVal = INT_MAX;
	int minIndex = -1;
	for (int i = 0; i < SIZE; i++) {
		if (!visited[i] && d[i] < minVal) {
			minIndex = i;
			minVal = d[i];
		}
	}
	return minIndex;
}

void printSolution(int *d) {
	cout << "Vertex" << "\t\t" << "Dist" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << i << "\t\t" << d[i] << endl;
	}
}

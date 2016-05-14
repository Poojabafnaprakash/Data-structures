#include <fstream>
#include <iostream>
using namespace std;
#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))
int nonZeroEdges; /* The number of nonzero edges in the graph */
int numberOfNodes; /* The number of nodes in the graph */
long dist[GRAPHSIZE][GRAPHSIZE]; /* dist[i][j] is the distance between node i and j; or INFINITY if there is no direct connection */
long shortestLength[GRAPHSIZE]; /* shortestLength[i] is the length of the shortest path between the source (s) and node i */
int prev[GRAPHSIZE]; /* prev[i] is the node that comes right before i in the shortest path from the source to i*/
char city[10][30]{
	"Montgomery-Alabama",
	"Juneau-Alaska",
	"Phoenix-Arizona",
	"Little_Rock-Arkansas",
	"Sacramento-California",
	"Denver-Colorado",
	"Hartford-Connecticut",
	"Dover-Delaware",
	"Tallahassee-Florida",
	"Atlanta-Georgia",
};
void printDistance() {
	int i;
	cout<<"Distances:"<<endl;
	for (i = 1; i <= numberOfNodes; ++i)
		cout<<city[i]<<"---"<<shortestLength[i]<<"\t";
		cout<<endl;
	}
/*
* Prints the shortest path from the source to dest.
*
* dijkstra(int) MUST be run at least once BEFORE
* this is called
*/
void printPath(int dest) {
	if (prev[dest] != -1)
		printPath(prev[dest]);
		//printf("%d ", dest);
		cout<<"-->";
		cout<<city[dest];
	}
void dijkstra(int s) {
	int i, k, mini;
	int visited[GRAPHSIZE];
	for (i = 1; i <= numberOfNodes; ++i) {
		shortestLength[i] = INFINITY;
		prev[i] = -1; /* no path has yet been found to i */
		visited[i] = 0; /* the i-th element has not yet been visited */
	}
	shortestLength[s] = 0;
	for (k = 1; k <= numberOfNodes; ++k) {
		mini = -1;
		for (i = 1; i <= numberOfNodes; ++i)
			if (!visited[i] && ((mini == -1) || (shortestLength[i] < shortestLength[mini])))
				mini = i;
		visited[mini] = 1;
		for (i = 1; i <= numberOfNodes; ++i)
			if (dist[mini][i])
				if (shortestLength[mini] + dist[mini][i] < shortestLength[i]) {
					shortestLength[i] = shortestLength[mini] + dist[mini][i];
					prev[i] = mini;
				}
	}
}
int main(int argc, char *argv[]) {
	int i, j;
	int u, v, w;
	FILE *fin = fopen("dist.txt", "r");
	fscanf(fin, "%d", &nonZeroEdges);
	for (i = 0; i < nonZeroEdges; ++i)
		for (j = 0; j < nonZeroEdges; ++j)
			dist[i][j] = 0;
	numberOfNodes = -1;
	for (i = 0; i < nonZeroEdges; ++i) {
		fscanf(fin, "%d%d%d", &u, &v, &w);
		dist[u][v] = w;
		numberOfNodes = MAX(u, MAX(v, numberOfNodes));
	}
	fclose(fin);
	dijkstra(5);
	printDistance();
	cout << endl;
	for (i = 1; i <= numberOfNodes; ++i) {
		cout << "Path from " << city[i];
		printPath(i);
		cout << endl;
	}
	return 0;
}

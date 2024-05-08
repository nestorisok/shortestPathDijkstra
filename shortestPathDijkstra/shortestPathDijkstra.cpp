#include <iostream>

using namespace std;



const int vertAmt = 5;

void printGraph(int distance_list[]);
int minDist(int distance_list[], bool tracking_list[]);
void dijkstra(int grphArg[vertAmt][vertAmt], const int vertTot, int sourceVert);

int main(void) {
	int myGraph[vertAmt][vertAmt] = {	// 5 x 5 graph with vertices
					   { 0, 4, 0, 0, 0},	// 0 + 0 = 0
					   { 4, 0, 8, 0, 0},	// 4 + 0 = 4
					   { 0, 8, 0, 7, 0},	// 4 + 8 = 12
					   { 0, 0, 7, 0, 9},	// 12 + 7 = 19
					   { 0, 0, 0, 9, 0} };	// 19 + 9 = 28


	dijkstra(myGraph, vertAmt, 0);








	return 0;
}

void printGraph(int distance_list[]) {

	cout << "Vertex \t\t Distance from source vertex" << endl;
		for (int i = 0; i < vertAmt; i++) {
			cout << i << "\t\t" << distance_list[i] << endl;
		}

}

int minDist(int distance_list[], bool tracking_list[]) {

	int min = INT_MAX, min_src;

	for (int v = 0; v < vertAmt; v++) {
		if (tracking_list[v] == false && distance_list[v] <= min) {
			min = distance_list[v];	// keeping our min value to reuse in our 'if' conditional
			min_src = v;			// taking element num and returning it
		}

	}

	return min_src;


}

void dijkstra(int grphArg[vertAmt][vertAmt], const int vertTot, int sourceVert) {
	int distance_list[vertAmt];		//	keeping track of distances
	bool tracking_list[vertAmt];	//	bool tracking_list if its occupied

	for (int i = 0; i < vertTot; i++) {

		distance_list[i] = INT_MAX;		// setting everything in our distance_list to INT_MAX
		tracking_list[i] = false;		// tracking_list[i] setting everything to false
	}

	distance_list[sourceVert] = 0;		// setting our source vertice to 0.


	for (int j = 0; j < vertAmt - 1; j++) {
		int u = minDist(distance_list, tracking_list);	// finding the min distance
		tracking_list[u] = true;						// and setting our tracking list at that point to true


		for (int v = 0; v < vertAmt; v++) {
				
				// checking to see if tracking_list, graph coords points exist and if distance_list isn't INT_MAX
			if ((tracking_list[v] == false) && (grphArg[u][v]) && (distance_list[u] != INT_MAX) && (distance_list[u] + grphArg[u][v] < distance_list[v])) {

				distance_list[v] = distance_list[u] + grphArg[u][v];
			}


		}

	}

	printGraph(distance_list);
}
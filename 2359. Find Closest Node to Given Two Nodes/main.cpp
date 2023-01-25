#include <bits/stdc++.h>
using namespace std;

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
	int n = edges.size();
	vector<int> from_n1(n, -1);
	vector<int> from_n2(n, -1);

	// DFS from node1
	int start = node1;
	int distance = 0;
	vector<int> visited1(n, false);
	while (start != -1 && !visited1[start]) {
		from_n1[start] = distance;
		visited1[start] = true;
		start = edges[start];
		distance++;
	}

	// DFS from node2
	start = node2;
	distance = 0;
	vector<int> visited2(n, false);
	while (start != -1 && !visited2[start]) {
		from_n2[start] = distance;
		visited2[start] = true;
		start = edges[start];
		distance++;
	}
	
	// Find the minimum distance
	int minimum = INT_MAX;
	int index = -1;
	for (int i = 0; i < n; i++) {
		// we need to find the maximum of the distance from node1 to node and node2 to node
		// such that this distance is minimum with respect to other distances from node1 to node and node2 to node
		int temp = max(from_n1[i], from_n2[i]);
		if (from_n1[i] >= 0 && from_n2[i] >= 0) {

			// checking from the minimum maximum distance
			if (minimum > temp) {
				minimum = temp;
				index = i;
			}
		}
	}

	return index;
}

int main(){
	vector<int> edges = {4,4,8,-1,9,8,4,4,1,1};
	int node1 = 5;
	int node2 = 6;

	cout << closestMeetingNode(edges, node1, node2) << endl;

	return 0;
}
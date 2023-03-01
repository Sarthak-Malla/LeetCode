#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

Node* cloneGraph(Node* node) {
	// this will store the original node and the corresponding clone node
	unordered_map<Node*, Node*> hash;
	Node* cloneGraph(Node* node) {
		// base case
		if (node == nullptr)
			return nullptr;
		
		Node* root = new Node(node->val);
		hash[node] = root;

		queue<Node*> q;
		q.push(node);

		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();

			for (auto child : curr->neighbors) {
				if (hash.find(child) == hash.end()) {
					hash[child] = new Node(child->val);
					q.push(child);
				}

				hash[curr]->neighbors.push_back(hash[child]);
			}
		}

		return hash[node];
	}
}

int main(){
	adjList = {{2,4},{1,3},{2,4},{1,3}};
	Node* node = new Node(1, adjList);
	Node* clone = cloneGraph(node);

	return 0;
}
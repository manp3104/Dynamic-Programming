#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <queue>
#include <limits.h>

using namespace std;
#define INF INT_MAX

typedef pair<int, int> iPair;

class Graph{
	int V;
	list<iPair> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair> [V];
}
void Graph::addEdge(int u, int v, int w) {
	adj[v].push_back(make_pair(u, w));
	adj[u].push_back(make_pair(v, w));
}
void Graph::shortestPath(int s) {
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
	vector<int> dist(V, INF);
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		list<iPair> ::iterator it;

		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = (*it).first;
			int weight = (*it).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	for (int i = 0; i < dist.size(); i++) {
		cout << i << ": \t" << dist[i] << endl;
	}
}

int main() {
	int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

	system("pause");
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int>_pair;

struct creatGraph
{
	int Vec;
	int Edg;
	vector<pair<int, _pair>> _edge;

	creatGraph(int Vec){
		this->Vec = Vec;
	}
	void addEdge(int u, int v, int w){
		_edge.push_back({ w,{u,v} });
	}
	int kruskal();
};

struct DisjointSets
{
	int* parent;
	int* _rank;
	int n;

	DisjointSets(int n){
		this->n=n;
		parent=new int[n + 1];
		_rank=new int[n + 1];

		for (int i = 0; i <= n; i++){
			_rank[i]=0;
			parent[i]=i;
		}
	}

	int searchVertex(int u){
		if (u != parent[u]){
			parent[u] = searchVertex(parent[u]);
		}
		return parent[u];
	}

	void merge(int x, int y){
		x = searchVertex(x), y = searchVertex(y);
		if (_rank[x] > _rank[y]) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
		if (_rank[x] == _rank[y]) {
			_rank[y]++;
		}
	}
};

int creatGraph::kruskal()
{
	int pathWeight=0;
	sort(_edge.begin(), _edge.end());

	DisjointSets _disjointset(Vec);

	vector<pair<int,_pair>>::iterator it;

	for (it = _edge.begin(); it != _edge.end(); it++){
		int u = it->second.first;
		int v = it->second.second;

		int set_u = _disjointset.searchVertex(u);
		int set_v = _disjointset.searchVertex(v);

		if (set_u != set_v){
			pathWeight+= it->first;
			_disjointset.merge(set_u, set_v);
		}
	}
	return pathWeight;
}

int main(){
	int N;
	int u, v, w;
	cin >> N;
	creatGraph g(N);
	while (cin >> u >> v >> w) {
		g.addEdge(u,v,w);
	}
	int pathWeight = g.kruskal();
	cout <<pathWeight;
	return 0;
}

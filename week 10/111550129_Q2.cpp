#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define eb emplace_back
const int N = 20;
vector<int> G[N];
vector<vector<int>> ans;

int s, t;
void dfs(int u, vector<int> &path) {
	path.eb(u);
	if(u == t) {
		ans.eb(path);
		path.pop_back();
		return;
	}

	for(auto& v : G[u]) {
		dfs(v, path);
	}
	path.pop_back();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i) {
    	int u, v; cin >> u >> v;
    	G[u].eb(v);
	}

	for(int i = 0; i < n; ++i)
		sort(G[i].begin(), G[i].end());

	cin >> s >> t;
	vector<int> v;
	dfs(s, v);
	for(auto& i : ans) {
		for(int j = 0; j < (int)i.size(); ++j)
			cout << i[j] << " \n"[j == (int)i.size() - 1];
	}

	if(ans.size() == 0)
		cout << "-1\n";
    return 0;
}

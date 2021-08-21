#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int n; 
int par[301];
int tier[301];

int find_par(int u){
	if(par[u] == u) return u;
	
	return par[u] = find_par(par[u]);
}

bool merge(int u, int v){
	u = find_par(u);
	v = find_par(v);
	
	if(u == v) return false;
	
	if(tier[u] > tier[v]) swap(u, v);
	par[u] = v;
	if(tier[u] == tier[v]) tier[v]++;
	return true;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for(int i = 0; i <= n; i++){
		par[i] = i;
	}
	
	struct EDGE{ int s; int e; int w;};
	vector<EDGE> edge(n*(n+1)/2);
	
	int w;
	int index = 0;
	for(int i = 1; i <= n; i++){
		cin >> w;
		edge[index].s = 0, edge[index].e = i, edge[index].w = w;
		index++;
	}
	
	int **input = new int*[n];
	for(int i = 0; i < n; i++){
		input[i] = new int[n];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> input[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			edge[index].s = i+1, edge[index].e = j+1, edge[index].w = input[i][j];
			index++;
		}
	}
	
	sort(edge.begin(), edge.end(), [&](EDGE a, EDGE b){return a.w < b.w;});
	
	long long ans = 0;
	for(int i = 0; i < edge.size(); i++){
		if(!merge(edge[i].s, edge[i].e)) continue;
		ans += edge[i].w;
	}
	
	cout << ans;
	
	return 0;
}


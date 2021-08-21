#include <iostream>

using namespace std;

int n, m;
int par[201];
int tier[201];


int find_par(int u){
	if(par[u] == u) return u;
	
	return par[u] = find_par(par[u]);
}

bool comp(int u, int v){
	return find_par(u) == find_par(v);
}

void merge(int u, int v){
	u = find_par(u);
	v = find_par(v);
	
	if(u == v) return;
	
	if(tier[u] > tier[v]) swap(u, v);
	par[u] = v;
	if(tier[u] == tier[v]) tier[v]++;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++){
		par[i] = i;
	}
	
	int link;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> link;
			if(link == 1) merge(i, j);
		}
	}
	
	int travel[m];
	for(int i = 0; i < m; i++){
		cin >> travel[i];
	}
	
	while(m--){
		if(!comp(travel[m], travel[m-1])) break;
	}
	
	if(m == 0) cout << "YES";
	else cout << "NO";
}


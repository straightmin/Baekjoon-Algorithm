#include <iostream>

using namespace std;

int n, m;
int par[1010101];
int tier[1010101];


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
	int q, u, v;
	
	for(int i = 0; i <= n; i++){
		par[i] = i;
	}
	
	while(m--){
		cin >> q >> u >> v;
		if(q == 0){
			merge(u, v);
		} else {
			if(comp(u, v)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}


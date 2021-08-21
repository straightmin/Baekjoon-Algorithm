#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
int par[101010];
int tier[101010];

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
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		par[i] = i;
	}
	
	struct EDGE{ int s; int e; int w;};
	vector<EDGE> edge(m);
	
	long long sum = 0;
	for(int i = 0; i < m; i++){
		cin >> edge[i].s >> edge[i].e >> edge[i].w;
		sum += edge[i].w;
	}
	
	sort(edge.begin(), edge.end(), [&](EDGE a, EDGE b){return a.w < b.w;});
	
	int cnt = 0;
	long long ans = 0;
	for(int i = 0; i < m; i++){
		if(!merge(edge[i].s, edge[i].e)) continue;
		cnt++;
		ans += edge[i].w;
	}
	
	ans = sum - ans;
	if(cnt != n-1) ans = -1;
	cout << ans;
	return 0;
}


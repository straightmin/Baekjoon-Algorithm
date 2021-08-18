#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > graph;
bool visit[2000];

bool dfs(int curr, int depth){
	if(depth == 5) return true;
	visit[curr] = true;
	
	for(int i = 0; i < graph[curr].size(); i++){
		int next = graph[curr][i];
		if(visit[next]) continue;
		
		if(dfs(next, depth+1)) return true;
	}
	
	visit[curr] = false;
	
	return false;
}

int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	
	while(m--){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++){
		if(graph[i].size() == 0) continue;
		
		memset(visit, false, sizeof(visit));
		if(dfs(i, 1)){
			cout << "1";
			return 0;
		}
	}
	
	cout << "0";
	return 0;
}


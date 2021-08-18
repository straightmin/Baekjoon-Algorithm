#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > v;
vector<int> parent;
vector<bool> visit;

void bfs(){
	queue<int> q;
	q.push(1);
	visit[1] = true;
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int i = 0; i < v[curr].size(); i++){
			int next = v[curr][i];
			if(visit[next]) continue;
			q.push(next);
			visit[next] = true;
			parent[next] = curr;
		}
	}
}

int main(){
	cin >> n;
	v.resize(n+1);
	parent.resize(n+1);
	visit.assign(n+1, false);
	
	int a, b;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs();
	for(int i = 2; i <= n; i++){
		cout << parent[i] << '\n';
	}
}


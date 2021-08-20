#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int n, l, r;
int map[50][50];
bool visit[50][50];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool in(int y, int x){
	return (y >= 0 && y < n && x >= 0 && x < n);
}

bool bfs(int y, int x){
	queue<pair<int, int> > q;
	queue<pair<int, int> > open;
	int count = 1;
	int population = map[y][x];
	q.push({y, x});
	open.push({y, x});
	visit[y][x] = true;
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		int cy = curr.first;
		int cx = curr.second;
		
		for(int i = 0; i < 4; i++){
			y = dy[i] + cy;
			x = dx[i] + cx;
			
			if(!in(y, x)) continue;
			int diff = abs(map[y][x] - map[cy][cx]);
			if(diff < l || diff > r) continue;
			if(visit[y][x]) continue;
			
			population += map[y][x];
			q.push({y, x});
			open.push({y, x});
			visit[y][x] = true;
			count++;
		}
	}
	population /= count;
	while(!open.empty()){
		pair<int, int> opend = open.front();
		open.pop();
		map[opend.first][opend.second] = population;
	}
	
	if(count == 1) return false;
	return true;
}

int main(){
	cin >> n >> l >> r;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	bool opend = true;
	int day = 0;
	while(true){
		opend = false;
		fill(visit[0], visit[49]+50, false);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visit[i][j]) continue;
				if(bfs(i, j)) opend = true;
			}
		}
		if(!opend) break;
		day++;
	}
	
	cout << day;
}


#include <iostream>
#include <queue>

using namespace std;

int n;
int map[300][300];
int visit[300][300];
int dy[] = {-2,-1,1,2,2,1,-1,-2};
int dx[] = {1,2,2,1,-1,-2,-2,-1};

void set(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

bool in(int y, int x){
	return (y >= 0 && y < n && x >= 0 && x < n);
}

int bfs(int y, int x, int ey, int ex){
	queue<pair<int, int> > q;
	q.push({y, x});
	visit[y][x] = true;
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		int cy = curr.first;
		int cx = curr.second;
		
		for(int i = 0; i < 8; i++){
			y = dy[i] + cy;
			x = dx[i] + cx;
			
			if(!in(y, x)) continue;
			if(visit[y][x]) continue;
			
			q.push({y, x});
			visit[y][x] = true;
			map[y][x] = map[cy][cx] + 1;
			if(y == ey && x == ex) return map[y][x];
		}
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		set();
		
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;
		cout << bfs(sy, sx, ey, ex) << '\n';
	}
	
	return 0;
}


#include <iostream>
#include <queue>

using namespace std;

int w, h;
int map[50][50];
bool visit[50][50];
int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

void set(int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			visit[i][j] = false;
		}
	}
}

bool in(int y, int x){
	return (y >= 0 && y < h && x >= 0 && x < w);
}

void bfs(int y, int x){
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
			if(map[y][x] == 0) continue;
			if(visit[y][x]) continue;
			
			q.push({y, x});
			visit[y][x] = true;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(true){
		cin >> w >> h;
		if(w == 0) break;
		
		set(h, w);
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
			}
		}
		
		int count = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(map[i][j] == 0) continue;
				if(visit[i][j]) continue;
				
				bfs(i, j);
				count++;
			}
		}
		
		cout << count << '\n';
	}
}


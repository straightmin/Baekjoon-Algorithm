#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
char map[1000][1000];
int dist[1000][1000][2];
bool visit[1000][1000][2];
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

bool in(int y, int x){
	return (y >= 0 && y < n && x >= 0 && x < m);
}

void bfs(int y, int x){
	queue<pair<pair<int, int>, int> > q;
	q.push({{y, x}, 0});
	visit[y][x][0] = true;
	
	while(!q.empty()){
		pair<int, int> curr = q.front().first;
		int wall = q.front().second;
		q.pop();
		int cy = curr.first;
		int cx = curr.second;
				
		for(int i = 0; i < 4; i++){
			y = dy[i] + cy;
			x = dx[i] + cx;
			
			if(!in(y, x)) continue;
			if(map[y][x] == '1'){
				if(wall == 0){
					q.push({{y, x}, 1});
					visit[y][x][1] = true;
					dist[y][x][1] = dist[cy][cx][0] + 1;
				}
				continue;
			}
			if(visit[y][x][wall]) continue;
			
			q.push({{y, x}, wall});
			visit[y][x][wall] = true;
			dist[y][x][wall] = dist[cy][cx][wall] + 1;
		}
	}
}

int main(){
	cin >> n >> m;
	string input;
	
	for(int i = 0; i < n; i++){
		cin >> input;
		for(int j = 0; j < m; j++){
			char ch = input.at(j);
			map[i][j] = ch;
		}
	}
	
	dist[0][0][0] = 1;
	bfs(0, 0);
	
	int a = dist[n-1][m-1][0];
	int b = dist[n-1][m-1][1];
	
	if(a == 0 && b == 0){
		cout << "-1";
	} else if(b == 0){
		cout << a;
	} else if(a == 0){
		cout << b;
	} else{
		cout << min(a, b);
	}
	
	return 0;
}


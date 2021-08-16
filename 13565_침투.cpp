#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int map[1000][1000];
bool visit[1000][1000];
int m, n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool in(int y, int x){
    return (y >= 0 && y < n && x >= 0 && x < m);
}

bool bfs(int y, int x){
    queue<pair<int, int> > q;
    q.push({y, x}); 
    visit[y][x] = true;
    
    while(!q.empty()){
        pair<int, int> next = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            y = dy[i] + next.first;
            x = dx[i] + next.second;
            
            if(!in(y, x)) continue;
            if(map[y][x] == 1) continue;
            if(visit[y][x]) continue;
            
            if(y == n-1) return true;
            q.push({y, x});
            visit[y][x] = true;
        }
    }
    
    return false;
}

int main(){
    cin >> n >> m;
    string input;
    
    for(int i = 0; i < n; i++){
    	cin >> input;
        for(int j = 0; j < m; j++){
        	char ch = input.at(j);
        	map[i][j] = ch - '0';
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << map[i][j];
        }
        cout << '\n';
    }
    
    for(int i = 0; i < m; i++){
    	if(map[0][i] == 1) continue;
        if(bfs(0, i)){
        	cout << "YES";
        	return 0;
		}
    }
    
   	cout << "NO";
    return 0;
}


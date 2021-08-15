#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int map[100][100];
bool visit[100][100];
int n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool in(int y, int x){
    return (y >= 0 && y < n && x >= 0 && x < n);
}

void bfs(int y, int x, int color, bool blind){
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
            if(blind){
                if(color%2 != map[y][x]%2)
                    continue;
            } else {
                if(color != map[y][x])
                    continue;
            }
            if(visit[y][x]) continue;
            
            q.push({y, x});
            visit[y][x] = true;
        }
    }
}

int main(){
    cin >> n;
    string input;
    
    for(int i = 0; i < n; i++){
        cin >> input;
        for(int j = 0; j < n; j++){
            char ch = input.at(j);
            if(ch == 'R') map[i][j] = 0;
            else if(ch == 'G') map[i][j] = 2;
            else map[i][j] = 1;
        }
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j]) continue;
            bfs(i, j, map[i][j], false);
            count++;
        }
    }
    cout << count << ' ';
    
    fill(visit[0], visit[n-1]+n, false);
    count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j]) continue;
            bfs(i, j, map[i][j], true);
            count++;
        }
    }
    cout << count;
}


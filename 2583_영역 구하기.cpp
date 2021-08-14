#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool map[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool in(int y, int x){
    return (y >= 0 && y < n && x >= 0 && x < m);
}

int bfs(int y, int x){
    queue<pair<int, int> > q;
    q.push({y, x});
    map[y][x] = true;
    int area = 1;
    
    while(!q.empty()){
        pair<int, int> next = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            y = dy[i] + next.first;
            x = dx[i] + next.second;
            
            if(!in(y, x)) continue;
            if(map[y][x]) continue;
            
            q.push({y, x});
            map[y][x] = true;
            area++;
        }
    }
    
    return area;
}

int main(){
    int k;
    cin >> n >> m >> k;
    
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                map[i][j] = true;
            }
        }
    }
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]) continue;
            
            v.push_back(bfs(i, j));
        }
    }
    
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
}


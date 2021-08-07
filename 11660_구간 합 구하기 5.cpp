#include <iostream>

using namespace std;

int n, m;
int DP[1025][1025];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> DP[i][j];
            
            DP[i][j] += DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1];
        }
    }
    
    int x1, y1, x2, y2; 
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1] << '\n';
    }
    
    
    return 0;
}


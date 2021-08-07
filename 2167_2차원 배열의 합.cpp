#include <iostream>

using namespace std;

int n, m;
int DP[301][301]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> DP[i][j];
            DP[i][j] += DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1];
        }
    }
    
    int tc;
    cin >> tc;
    int i, j, x, y;
    while(tc--){
        cin >> i >> j >> x >> y;
        cout << DP[x][y] - DP[x][j-1] - DP[i-1][y] + DP[i-1][j-1] << '\n';
    }
    
    return 0;
}


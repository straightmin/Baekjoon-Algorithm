#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n;
    int DP[n+1] = {};
    
    for(int i = 1; i <= n; i++){
        cin >> DP[i];
        DP[i] += DP[i-1];
    }
    
    cin >> m;
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << DP[e] - DP[s-1] << '\n';
    }
    
    return 0;
}


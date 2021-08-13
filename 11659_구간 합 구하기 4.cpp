#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n+1] = {0};
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    int i, j;
    while(m--){
        cin >> i >> j;
        cout << arr[j]-arr[i-1] << '\n';
    }
    
    return 0;
}


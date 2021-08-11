#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    vector<int> DP;
    vector<int> arr;
    vector<int> D;
    int maximum = 0;
    
    int n;
    cin >> n;
    arr.resize(n);
    D.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    DP.push_back(arr[0]);
    
    for(int i = 1; i < n; i++){
        if(DP.back() < arr[i]){
            DP.push_back(arr[i]);
            
            D[i] = DP.size() - 1;
        } else {
            auto idx = lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin();
            DP[idx] = arr[i];
            D[i] = idx;
        }
    }
    
    cout << DP.size();
    
    return 0;
}


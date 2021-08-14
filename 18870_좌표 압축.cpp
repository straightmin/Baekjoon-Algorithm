#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    vector<int> arr(n), sorted(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    int s, e, mid;
    for(int i = 0; i < n; i++){
        s = 0; e = sorted.end()-sorted.begin();
        while(s<e){
            mid = (s+e)/2;
            if(sorted[mid] < arr[i]){
                s = mid+1;
            } else{
                e = mid;
            }
        }
        cout << e << ' ';
    }
    
    return 0;
}


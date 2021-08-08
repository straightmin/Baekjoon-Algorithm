#include <iostream>
#include <algorithm>

using namespace std;

int k, n;

bool check(int lan[], int length){
    int cnt = 0;
    
    for(int i = 0; i < k; i++){
        cnt += lan[i] / length;
        
        if(cnt >= n) return true;
    }
    
    return false;
}

int main(){
    cin >> k >> n;
    int lan[k];
    
    for(int i = 0; i < k; i++){
        cin >> lan[i];
    }
    
    sort(lan, lan+k);
    long long s = 1, e = lan[k-1];
    int ans = 0;
    while(s <= e){
        long long mid = (s+e)/2;
        
        if(check(lan, mid)){
            ans = mid;
            s = mid + 1;
        } else{
            e = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}


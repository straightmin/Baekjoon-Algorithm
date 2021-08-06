#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cnt(8001, 0);
    
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        int index = v[i]+4000;  // range: -4000 ~ 4000
        cnt[index]++;
    }
    cout << floor(sum / n + 0.5) << '\n';   // floor(n+0.5) == round(n)
    sort(v.begin(), v.end());
    cout << v[n/2] << '\n';
    
    int max = 0;
    for(int i = 0; i < 8001; i++) {
        if(max < cnt[i]){
            max = cnt[i];
        }
    }
    
    bool flg = false;   // find second smallest val
    int mode;
    for(int i = 0 ; i < 8001; i++) {
        if(max == cnt[i]){
            mode = i-4000;
            if(flg) break;
            flg = true;
        }
    }
    cout << mode << '\n';
    cout << v[n-1] - v[0] << '\n';
    
}


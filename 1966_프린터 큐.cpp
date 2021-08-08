#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void solve(){
    int n, index, num;
    queue<pair<int, int> > q;
    cin >> n >> index;
    int doc[10] = {};
    
    for(int i = 0; i < n; i++){
        cin >> num;
        q.push({num, i});
        doc[num]++;
    }
    
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        int i;
        for(i = curr.first+1; i < 10; i++){
            if(doc[i] > 0) break;
        }
        if(i < 10){
            q.push(curr);
            q.pop();
            continue;
        }
        
        cnt++;
        q.pop();
        doc[curr.first]--; 
        if(curr.second == index)
            break;
    }
    
    cout << cnt << '\n';
}

int main(){
    int tc;
    cin >> tc;
    
    while(tc--){
        solve();
    }
    return 0;
}


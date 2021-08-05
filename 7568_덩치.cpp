#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<pair<int, int> > v;
vector<int> rate;

int main(){
    cin >> n;
    v.resize(n);
    rate.assign(n, 1);
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                rate[i]++;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << rate[i] << " ";
    }
    
    
    return 0;
}

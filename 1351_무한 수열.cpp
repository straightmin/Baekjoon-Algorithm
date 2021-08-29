#include <iostream>
#include <map>
#define ll long long

using namespace std;

ll n, p, q;
map<ll, ll> dp;

ll get(ll n){
    if(n == 0) return dp[0];
    if(n == 1) return dp[1];
    
    if(dp[n]) return dp[n];
    
    return dp[n] = get(n/p) + get(n/q);
}

int main(){
	cin >> n >> p >> q;
	
	dp[0] = 1l;
	dp[1] = 2l;
    
    cout << get(n);
    
    return 0;
}


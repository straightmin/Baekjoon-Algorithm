#include <iostream>
#include <string>

using namespace std;

unsigned int bit = 0;

void solve(){
    string str;
    cin >> str;
    
    if(str == "all"){
        bit = -1;
    } else if(str == "empty"){
        bit = 0;
    } else{
        int x;
        cin >> x;
        if(str == "add"){
            bit |= 1 << (x-1);
        } else if(str == "remove"){
            bit &= ~(1 << (x-1));
        } else if(str == "check"){
            if(bit & 1 << (x-1)) cout << "1\n";
            else cout << "0\n";
        } else if(str == "toggle"){
            bit ^= 1 << (x-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    while(n--){
        solve();
    }
    
    return 0;
}


#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    
    string ans;
    stack<int> s;
    int index = 0;
    while(n--){
        cin >> m;
        
        while(index < m){
            s.push(++index);
            ans.append("+\n");
        }
        
        if(s.top() != m){
            cout << "NO";
            return 0;
        }
        
        s.pop();
        ans.append("-\n");
    }
    
    cout << ans;
    return 0;
}


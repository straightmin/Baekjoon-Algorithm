#include <iostream>
#include <stack>
#include <string>

using namespace std;

string check(string str){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int len = str.size();
    stack<int> s;
    
    for(int i = 0; i < len; i++){
        char ch = str.at(i);
        
        if(ch == '(') s.push(1);
        else if(ch == '[') s.push(2);
        else if(ch == ')'){
            if(s.empty() || s.top() != 1) return "no";
            s.pop();
        }
        else if(ch == ']'){
            if(s.empty() || s.top() != 2) return "no";
            s.pop();
        }
    }
    
    if(!s.empty()) return "no";
    return "yes";
}

int main(){
    string str;
    
    while(1){
        getline(cin, str);
        if(str.size() == 1) break;
        cout << check(str) << '\n';
    }
    
    
    return 0;
}


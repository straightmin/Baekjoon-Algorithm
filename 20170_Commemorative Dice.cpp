#include <iostream>

using namespace std;

int lcm(int a, int b){
    if(a%b == 0)
        return b;
    
    return lcm(b, a%b);
}

int main(){
    int dice[2][6];
    int win = 0;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            cin >> dice[i][j];
        }
    }
    
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            if(dice[0][i] > dice[1][j])
                win++;
    
    int c = lcm(win, 36);
    
    cout << win/c << '/' << 36/c;
    
    return 0;
}


#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = 666;
    int find = 666;
    
    for(int i = find; n; i++){
        int tmp = i;
        while(tmp > 99){
            if(tmp%10 == 6){
                tmp /= 10;
                if(tmp%10 == 6){
                    tmp /= 10;
                    if(tmp%10 == 6){
                        tmp = 0;
                        ans = i;
                        n--;
                        break;
                    } else {
                        tmp /= 10;
                    }
                } else {
                    tmp /= 10;
                }
            } else {
                tmp /= 10;
            }
        }
    }
    
    cout << ans;
    return 0;
}


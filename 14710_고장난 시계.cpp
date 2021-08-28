#include <iostream>

using namespace std;

int main(){
    int hour, minute;
    cin >> hour >> minute;
    
    while(minute > 0 && minute < 360){
        minute += 12;
        hour += 1;
    }
    
    if(hour%30 == 0 && minute%360 == 0)
        cout << 'O';
    else
        cout << 'X';
}


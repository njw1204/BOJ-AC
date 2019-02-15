#include <iostream>
using namespace std;

int main(){
    int N, result = 1;
    cin >> N;
    
    switch(N){
        case 12: result*=12;
        case 11: result*=11;
        case 10: result*=10;
        case 9:  result*=9;
        case 8:  result*=8;
        case 7:  result*=7;
        case 6:  result*=6;
        case 5:  result*=5;
        case 4:  result*=4;
        case 3:  result*=3;
        case 2:  result*=2;
        case 1:  result*=1;
        default: result*=1;
    }
    
    cout << result;
    return 0;
}
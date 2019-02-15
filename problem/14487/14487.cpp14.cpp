#include <iostream>
using namespace std;

int main(){
    int N, sum=0, max=-1;
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        if(input>max) max=input;
        sum += input;
    }
    cout << sum - max;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    long long N, value=0, i=0;
    cin >> N;
    while(value<=N){
        i++;
        value=i*(i+1)/2;
    }
    cout << i-1;
}
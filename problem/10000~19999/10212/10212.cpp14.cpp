#include <iostream>
using namespace std;

int main(){
    int a;
    if((long long)&a%3) cout << "Yonsei";
    else cout << "Korea";
    return 0;
}
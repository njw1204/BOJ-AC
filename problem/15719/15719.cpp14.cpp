#include <iostream>
using namespace std;

unsigned long long n, x;
unsigned long long s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> x;
      s += x;
    }
    s -= n * (n - 1) / 2;
    cout << s;
}      
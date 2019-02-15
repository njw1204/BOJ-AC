#include <iostream>
using namespace std;

int main(){
  int fibo[45]={1,1};
  int N;
  cin >> N;
  for (int i=2;i<N;i++){
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
  cout << fibo[N-1];
  return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  for(;;){
    int A, B;
    if(scanf("%d%d",&A,&B)==EOF) break;
    cout << A+B << '\n';
  }
  return 0;
}
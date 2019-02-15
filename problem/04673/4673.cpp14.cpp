#include <iostream>
using namespace std;

int d(int num){
  int result = num;
  for(int i=1;num>=i;i*=10){
    result += (num%(i*10)) / i;
  }
  return result;
}

int main(){
  static bool selfnum_not_flag[10001] = {0};
  for(int i=1;i<=10000;i++){
    selfnum_not_flag[d(i)] = true;
    if(selfnum_not_flag[i]==false) cout << i << endl;
  }
  return 0;
}
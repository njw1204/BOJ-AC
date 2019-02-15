#include <iostream>
using namespace std;

int IsPrimeNum(int num){
  if(num==1 || num==4) return 0;
  else if(num==2 || num==3) return 1;
  else{
    for(int i=2;i<num/2;i++){
      if(num%i==0) return 0;
    }
    return 1;
  }
}

int main(){
  int N, count = 0;
  cin >> N;

  for(int i=0;i<N;i++){
    int input;
    cin >> input;
    if(IsPrimeNum(input)) count++;
  }

  cout << count;
  return 0;
}
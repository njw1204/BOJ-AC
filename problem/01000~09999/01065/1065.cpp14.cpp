#include <iostream>
using namespace std;

bool IsHansu(int num){
  if(num<100) return true;
 
  int n=(num/10)%10; // 특정 자리수값 저장
  const int diff=num%10-(num/10)%10; // 일의자리 - 십의자리
  num/=100;
    
  while(num>0){
    if(n-(num%10)!=diff) return false;
    n=num%10;
    num/=10;
  }
    
  return true;
}

int main() {
	int N, count=0;
    cin >> N;
    
    for(int i=1;i<=N;i++){
      if(IsHansu(i)) count++;
    }
    
    cout << count;
	return 0;
}
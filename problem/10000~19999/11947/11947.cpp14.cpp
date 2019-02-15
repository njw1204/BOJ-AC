#include <iostream>
using namespace std;

long long GetMaxLove(long long num) {
  int temp=num/10;
  long long digit=1;
  
  while(temp>0){
    digit*=10;
    temp/=10;
  }
    
  if(num>=digit*5-1) return (digit*5)*(digit*5-1);
  else return num*(digit*10-1-num);
}

int main() {
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
      int input;
      cin >> input;
      cout << GetMaxLove(input) << '\n';
    }
	return 0;
}
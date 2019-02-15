#include <iostream>
using namespace std;

int main(){
  int N, val1, val2, count=0;
  cin >> N;
  int val3 = N;
  do{
    val1 = val3%10;
    val2 = (val3/10+val1)%10;
    val3 = val1*10+val2;
    count++;
  }while(val3!=N);
  cout << count;
  return 0;
}
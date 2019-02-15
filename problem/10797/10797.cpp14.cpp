#include <iostream>
using namespace std;

int main(){
  int day, result = 0;
  cin >> day;

  for(int i=0;i<5;i++){
    int input;
    cin >> input;
    if(input==day) result++;
  }

  cout << result;
  return 0;
}
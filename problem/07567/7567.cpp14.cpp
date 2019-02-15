#include <iostream>
#include <string>
using namespace std;

int main(){
  string input;
  int result = 0;
  cin >> input;

  for(int i=0;i<input.size();i++){
    if(i==0){
      result += 10;
      continue;
    }

    if(input[i]==input[i-1]) result +=5;
    else result += 10;
  }

  cout << result;
  return 0;
}
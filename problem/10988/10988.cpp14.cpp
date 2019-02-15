#include <iostream>
#include <string>
using namespace std;

int main(){
  string myWord;
  cin >> myWord;
  
  if(myWord.size() < 2){
    cout << 1;
    return 0;
  }

  for(int i=0;i<myWord.size()/2;i++){
    if(myWord[i] != myWord[myWord.size()-i-1]){
      cout << 0;
      return 0;
    }
  }

  cout << 1;
  return 0;
}
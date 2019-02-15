#include <iostream>
#include <string>
using namespace std;

int main(){
  string user_input;
  for(int i=0;i<100;i++){
    getline(cin,user_input);
    cout << user_input << '\n';
  }
  return 0;
}
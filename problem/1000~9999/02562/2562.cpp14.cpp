#include <iostream>
using namespace std;

int main(){
  int max_num = 0, max_num_index = -1;

  for(int i=0;i<9;i++){
    int input;
    cin >> input;
    if(input > max_num){
      max_num = input;
      max_num_index = i;
    }
  }

  cout << max_num << '\n' << max_num_index+1;
  return 0;
}
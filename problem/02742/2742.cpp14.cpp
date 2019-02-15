#include <iostream>

int main(){
  int N;
  std::cin >> N;
  for(int i=N;i>=1;i--){
    std::cout << i;
    if(i>1) std::cout << '\n';
  }
}
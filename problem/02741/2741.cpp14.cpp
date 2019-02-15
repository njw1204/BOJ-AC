#include <iostream>

int main(){
  int N;
  std::cin >> N;
  for(int i=1;i<=N;i++){
    std::cout << i;
    if(i<N) std::cout << '\n';
  }
}
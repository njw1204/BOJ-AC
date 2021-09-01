#include <iostream>

int main(){
  int N;
  std::cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<=i;j++){
    std::cout << '*';
    }
    if(i!=N-1) std::cout << '\n';
  }
}
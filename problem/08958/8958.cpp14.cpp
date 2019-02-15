#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  cin.ignore(0xFFFFFFFF,'\n');

  for(int i=0;i<N;i++){
    int addPoint = 0, score = 0;
    while(1){
      char input = getchar();

      if(input == '\n') break;
      else if(input == 'O'){
        addPoint++;
        score += addPoint;
      }else{
        addPoint = 0;
      }
    }

    cout << score << '\n';
  }

  return 0;
}
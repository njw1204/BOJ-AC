#include <iostream>
using namespace std;

int IsInsideCircle(int x, int y, int circle_x, int circle_y, int circle_r){
  int dest = (x-circle_x) * (x-circle_x) +
             (y-circle_y) * (y-circle_y);
  int rad = circle_r * circle_r;

  if(dest<rad) return 1;
  else return 0;
}

int main(){
  int T;
  cin >> T;

  for(int i=0;i<T;i++){
    int count = 0;
    int my_x, my_y, fin_x, fin_y, circleCount;
    cin >> my_x >> my_y >> fin_x >> fin_y >> circleCount;
      
    for(int j=0;j<circleCount;j++){
      int circle_x, circle_y, circle_r;
      cin >> circle_x >> circle_y >> circle_r;
      count += IsInsideCircle(my_x,my_y,circle_x,circle_y,circle_r) ^
               IsInsideCircle(fin_x,fin_y,circle_x,circle_y,circle_r);
    }
      
    cout << count << '\n';
  }

  return 0;
}
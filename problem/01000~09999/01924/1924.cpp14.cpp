#include <iostream>

int main(){
  const char today_str[7][4]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  const int dayofmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int day = 0;
  int x, y;
  std::cin >> x >> y;
  for(int i=2;i<=x;i++){
    day += dayofmonth[i-2];
  }
  day+=y-1;
  printf("%s",today_str[day%7]);
}
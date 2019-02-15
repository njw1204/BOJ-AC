#include <iostream>

int arr_min_count[1000000]={0};
int min_way[4];

int main(){
  int N;
  std::cin >> N;
  for(int i=2;i<=N;i++){
    for(int j=0;j<4;j++) min_way[j]=0x7FFFFFFF;
    if(!(i%3) && (i/3>0)) min_way[0]=arr_min_count[i/3-1];
    if(!(i%2) && (i/2>0)) min_way[1]=arr_min_count[i/2-1];
    if(i-1>0) min_way[2]=arr_min_count[i-2];
    for(int j=0;j<3;j++) if(min_way[j]<min_way[3]) min_way[3]=min_way[j];
    arr_min_count[i-1]=min_way[3]+1;
  }
  std::cout << arr_min_count[N-1];
  return 0;
}
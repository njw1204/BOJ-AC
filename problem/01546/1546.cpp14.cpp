#include <iostream>
#include <cmath>

int main(){
  int N;
  double new_average=0;
  std::cin >> N;
  if(N==0) {printf("0"); return 0;}
  int* score = new int[N+1];
  for(int i=0;i<N;i++) std::cin >> score[i];
  score[N]=score[0];
  for(int i=1;i<N;i++){
    if(score[i]>score[N]) score[N]=score[i];
  }
  for(int i=0;i<N;i++){
    new_average+=(double)score[i]/score[N]*100;
  }
  printf("%.2f",new_average/N);
  delete[] score;
}
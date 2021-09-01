#include <iostream>
#define min(x,y) (((x)<(y))?(x):(y))
using namespace std;

int main(){
  int N;
  int cost[1000][3]={0};

  cin >> N;
  for(int i=0;i<N;i++) {
    for(int j=0;j<3;j++){
      cin >> cost[i][j];
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      if(i!=0) {
        if(j==0) cost[i][j] += min(cost[i-1][1],cost[i-1][2]);
        if(j==1) cost[i][j] += min(cost[i-1][0],cost[i-1][2]);
        if(j==2) cost[i][j] += min(cost[i-1][0],cost[i-1][1]);
      }
    }
  }

  cout << min(min(cost[N-1][0],cost[N-1][1]),cost[N-1][2]);
  return 0;
}
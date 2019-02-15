#include <iostream>
using namespace std;

struct PEOPLE{
  int weight;
  int height;
};

int main(){
  int N;
  cin >> N;

  PEOPLE* peArr = new PEOPLE[N];

  for(int i=0;i<N;i++){
    cin >> peArr[i].weight >> peArr[i].height;
  }

  for(int i=0;i<N;i++){
    int myRank = 1;
    for(int j=0;j<N;j++){
      if(i==j) continue;
      if(peArr[i].weight < peArr[j].weight && peArr[i].height < peArr[j].height)
        myRank++;
    }
    cout << myRank << ' ';
  }

  delete[] peArr;
  return 0;
}
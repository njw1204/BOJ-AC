#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct STUDENT{
 int country;
 int no;
 int score;
};

STUDENT arr[100];

int main() {
  int N;
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> arr[i].country
        >> arr[i].no
        >> arr[i].score;

  sort(arr, arr+N,
  [](const STUDENT& a, const STUDENT& b){
     return (a.score > b.score);
  });
  
  printf("%d %d\n%d %d\n",
         arr[0].country, arr[0].no,
         arr[1].country, arr[1].no);
  
  if (arr[2].country == arr[1].country &&
      arr[1].country == arr[0].country) {
   
    for(int i=0;i<N;i++) {
      if (arr[i].country != arr[0].country) {
        printf("%d %d", arr[i].country, arr[i].no);
        break;
      }
    }
      
  } else printf("%d %d", arr[2].country, arr[2].no);

  return 0;
}
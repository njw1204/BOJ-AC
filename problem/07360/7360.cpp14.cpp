#include <stdio.h>
#define ABS(x) ((x)>0)?(x):(-(x))

int main() {
  while(1) {
  int A[20], B[20], round, score[2]={0};
  scanf("%d",&round);
  if(round==0) break;
  for(int i=0;i<round;i++) scanf("%d",A+i);
  for(int i=0;i<round;i++) scanf("%d",B+i);
  for(int i=0;i<round;i++) {
    int diff=ABS(A[i]-B[i]);
    switch(diff) {
    case 0: continue;
    case 1:
      if(A[i]<B[i]) {
        if(A[i]==1) score[0]+=6;
        else score[0]+=A[i]+B[i];
      }else if(B[i]>1) score[1]+=A[i]+B[i];
      else score[1]+=6;
    break;
    default:
       if(A[i]>B[i]) score[0]+=A[i];
       else score[1]+=B[i];
    }
  }
  printf("A has %d points. B has %d points.\n\n",score[0],score[1]);
  }
  return 0;
}
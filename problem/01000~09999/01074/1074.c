#include <stdio.h>

int main() {
  int n,y,x,ans=0;
  scanf("%d%d%d",&n,&y,&x);
  n=1<<n;
  while(n>>=1){
    ans+=((y>=n)*2+(x>=n))*n*n;
    y%=n;
    x%=n;
  }
  printf("%d",ans);
  return 0;
}

#include <cstdio>

unsigned char isExist[1<<25>>3] = {};

int main(){
    int N;
    while(~scanf("%d",&N)){
      if(int(isExist[N/8] & (1 << (N%8)))==0) printf("%d ",N);
      isExist[N/8] |= 1 << (N%8);
    }
	return 0;
}
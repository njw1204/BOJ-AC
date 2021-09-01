#import<cstdio>
main(int H,int M,int S,int X){scanf("%d%d%d%d",&H,&M,&S,&X);S+=X;M+=S/60;S%=60;H+=M/60;M%=60;H%=24;printf("%d %d %d",H,M,S);}
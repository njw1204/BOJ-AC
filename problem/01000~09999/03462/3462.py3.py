for _ in range(int(input())):
 n,k=map(int,input().split())
 print(+((n-k)&((k-1)//2)==0))
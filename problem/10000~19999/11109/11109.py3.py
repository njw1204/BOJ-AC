for _ in range(int(input())):
 d,n,s,p=map(int,input().split())
 a,b=n*s,d+n*p
 if a>b: print("parallelize")
 elif a==b: print("does not matter")
 else: print("do not parallelize")
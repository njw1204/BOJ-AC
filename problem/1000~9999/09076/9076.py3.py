for _ in range(int(input())):
 x=sorted([*map(int,input().split())])
 ans=sum(x[1:4])
 if x[3]-x[1]>=4: print('KIN')
 else: print(ans)
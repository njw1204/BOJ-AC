n,k=map(int,input().split())
a=0
for i in map(int,input().split()): a+=(i+1)//2
if a<n: print('NO')
else: print('YES')
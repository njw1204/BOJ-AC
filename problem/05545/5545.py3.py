N=int(input())
money,b=map(int,input().split())
x=[0]*N
cal=int(input())
ans=cal/money
for i in range(N): x[i]=int(input())
x.sort(reverse=True)
for i in x:
 cal+=i
 money+=b
 ans=max(ans,cal/money)
print(int(ans))
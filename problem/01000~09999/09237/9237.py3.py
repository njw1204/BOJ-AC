n=int(input())
x=sorted(map(int,input().split()),reverse=True)
ans=0
for i in range(n):
    ans=max(ans,x[i]+2+i)
print(ans)
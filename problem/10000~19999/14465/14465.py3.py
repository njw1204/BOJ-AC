n,k,b=map(int,input().split())
x=[0]*(n+1)
for i in range(b):
    x[int(input())]=1

left,right=1,k
ans=n

cnt=0
for i in range(left,right+1):
    cnt+=x[i]
ans=cnt

while right<n:
    cnt+=x[right+1]-x[left]
    left+=1
    right+=1
    ans=min(ans,cnt)

print(ans)
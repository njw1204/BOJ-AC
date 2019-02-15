n=int(input())
ans=0

for i in range(2,n+1,2):
  if n-i>=4: ans+=(n-i)//2-1

print(ans)
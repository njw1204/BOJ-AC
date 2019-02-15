x,y=map(int,input().split())
ans=x/y
for i in range(int(input())):
  a,b=map(int,input().split())
  if a/b<ans:
    ans=a/b
print(ans*1000)
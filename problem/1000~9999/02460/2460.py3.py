now,ans=0,0
for i in range(10):
 A,B=map(int,input().split())
 now+=B-A
 ans=max(ans,now)
print(ans)
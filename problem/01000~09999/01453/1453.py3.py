arr=[0]*101
input();N=[*map(int,input().split())]
ans=0
for i in N:
 if arr[i]==0: arr[i]=1
 else: ans+=1
print(ans)
a,b=input().split()
bSum,ans=0,0
for i in b: bSum+=int(i)
for i in a: ans+=int(i)*bSum
print(ans)
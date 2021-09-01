lc,mod,cnt,ans="x",10**9+9,0,1
for i in input()+"x":
 if i==lc: cnt+=1
 else:
  if lc=="d": ans=10*pow(9,cnt,mod)*ans%mod
  if lc=="c": ans=26*pow(25,cnt,mod)*ans%mod
  lc,cnt=i,0
print(ans)
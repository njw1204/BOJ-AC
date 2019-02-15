n=int(input())
loss=[*map(int,input().split())]
gain=[*map(int,input().split())]
ans=0
for i in range(2**n):
 t1,t2,c=0,0,0
 while i:
  if i&1:
   t1+=loss[c]
   t2+=gain[c]
  i>>=1
  c+=1
 if t1<100: ans=max(ans,t2)
print(ans)
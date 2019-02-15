N=int(input())
D=tuple([*map(int,input().split())])
positivePos=-1

for i in range(N):
 if D[i]>=0:
  positivePos=i
  break

if positivePos==-1:
 print(D[-1]+D[-2])
 exit()
if positivePos==0:
 print(D[0]+D[1])
 exit()

pos2=positivePos
minValue,ans=10**10,0
for i in range(positivePos-1,-1,-1):
 for j in range(pos2,N):
  t=D[i]+D[j]
  abs_t=t if t>0 else -t
  
  if t>=0 or j==N-1:
   val1=D[i]+D[j-1] if j>positivePos else 10**10
   abs_val1=val1 if val1>0 else -val1
   
   if abs_val1<abs_t and abs_val1<minValue:
    minValue=abs_val1
    ans=val1
   elif abs_t<minValue:
    minValue=abs_t
    ans=t
 
   if j>pos2: pos2=j
   break

print(ans)
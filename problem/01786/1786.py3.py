T,P=input(),input()
lenT,lenP=len(T),len(P)

D=[0]*lenP
j=0
for i in range(1,lenP):
  while j>0 and P[j]!=P[i]: j=D[j-1]
  if P[j]==P[i]:
    D[i]=j+1
    j+=1

ans,ansList,i,j=0,[],0,0
while i<lenT:
  if T[i]==P[j]:
    if j==lenP-1:
      ans+=1
      ansList.append(i-lenP+2)
      j=D[j]
    else: j+=1
    i+=1
  else:
    if j: j=D[j-1]
    else: i+=1

print(ans)
print(' '.join(map(str,ansList)))
n,ans=int(input()),0
x=[0]*128
for i in input(): x[ord(i)]+=1
for i in range(n-1):
 fail=False
 t=[0]*128
 for j in input(): t[ord(j)]+=1
 diff=[]
 for j in range(ord('A'),ord('Z')+1):
  if x[j]!=t[j]: diff.append(t[j]-x[j])
 diff.sort()
 if diff==[] or diff==[1] or diff==[-1] or diff==[-1,1]: ans+=1
print(ans)
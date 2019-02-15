n,ans1,ans2=int(input()),0,0
x=[0]*n
for i in range(n): x[i]=input()
for i in range(n):
 for j in range(1,n):
  if x[i][j-1]==x[i][j]=='.' and (j==n-1 or x[i][j+1]=='X'): ans1+=1
  if x[j-1][i]==x[j][i]=='.' and (j==n-1 or x[j+1][i]=='X'): ans2+=1
print(ans1,ans2)
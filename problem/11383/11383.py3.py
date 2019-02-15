n,m=map(int,input().split())
x=[]
for i in range(n):
  x.append(list(input()))
for i in range(n):
  k=list(input())
  j=0
  while j<m*2:
    if x[i][j//2]==k[j]==k[j+1]:
      j+=2
    else:
      print('Not Eyfa')
      exit()
print('Eyfa')
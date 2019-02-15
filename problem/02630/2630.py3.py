def solve(si,sj,width):
 global x,a
 clear=True
 t=x[si][sj]
 for i in range(si,si+width):
  for j in range(sj,sj+width):
   if x[i][j]!=t:
    clear=False
    break
  if not clear: break
 if clear: a[t]+=1
 else:
  solve(si,sj,width//2)
  solve(si+width//2,sj,width//2)
  solve(si,sj+width//2,width//2)
  solve(si+width//2,sj+width//2,width//2)

n,x,a=int(input()),[],[0]*2
for _ in range(n): x.append([*map(int,input().split())])
solve(0,0,n)
print(a[0],a[1],sep='\n')
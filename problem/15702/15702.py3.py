N,M=map(int,input().split())
score=[*map(int,input().split())]
x=[]
for i in range(M):
  t=input().split()
  tt=0
  for j in range(N):
    if t[j+1]=='O':
      tt+=score[j]
  x.append((int(t[0]),tt))
x.sort(key=lambda x:(-x[1],x[0]))
print(x[0][0],x[0][1])
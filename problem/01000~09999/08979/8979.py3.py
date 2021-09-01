N,K=map(int,input().split())
L=[0]*N
for i in range(N):
 L[i]=[*map(int,input().split())]
 if L[i][0]==K: me=L[i]
L.sort(key=lambda x:(x[1],x[2],x[3]),reverse=True)
rank=1
for i in L:
 if (i[1],i[2],i[3])==(me[1],me[2],me[3]): break
 rank+=1
print(rank)
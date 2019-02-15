n=int(input())
edge=[[0]*111 for _ in range(111)]
for _ in range(int(input())):
    x,y=map(int,input().split())
    edge[x][y]=1

for i in range(n+1):
    for j in range(n+1):
        for k in range(n+1):
            if edge[j][i] and edge[i][k]:
                edge[j][k]=1

for i in range(1,n+1):
    a=0
    for j in range(1,n+1):
        if i!=j and not edge[i][j] and not edge[j][i]:
            a+=1
    print(a)
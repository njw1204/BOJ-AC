n,k=map(int,input().split())
field=[]
for i in range(n):
    field.append([*map(int,input().split())])
for i in range(n*k):
    for j in range(n*k):
        print(field[i//k][j//k], end=' ')
    print()
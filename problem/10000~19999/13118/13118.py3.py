X=list(map(int,input().split()))
N=int(input().split()[0])
for i,j in enumerate(X):
  if j==N:
    print(i+1)
    exit()
print(0)
n=int(input())
x=[]
for m,i in enumerate(reversed([*map(int,input().split())])): x.insert(i,str(n-m))
print(' '.join(x))
 
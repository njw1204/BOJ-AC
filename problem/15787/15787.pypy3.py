n,m=map(int,input().split())
x=[0]*n
k=2**20-1
for _ in range(m):
 o=[*map(int,input().split())]
 if o[0]==1: x[o[1]-1]|=1<<(o[2]-1)
 elif o[0]==2: x[o[1]-1]&=k^(1<<(o[2]-1))
 elif o[0]==3: x[o[1]-1]=(x[o[1]-1]<<1)&k
 else: x[o[1]-1]=(x[o[1]-1]>>1)&k
print(len(set(x)))
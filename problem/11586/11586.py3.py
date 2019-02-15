N=int(input())
M=[[0]*N for _ in range(N)]
for i in range(N): M[i]=list(input())
D=int(input())
if D==1:
 for i in M: print(''.join(i))
if D==2:
 for i in M: print(''.join(reversed(i)))
if D==3:
 for i in reversed(M): print(''.join(i))
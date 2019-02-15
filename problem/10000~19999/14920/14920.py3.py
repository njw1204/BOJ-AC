N,i=int(input()),1
while N>1:
 if N%2: N=3*N+1
 else: N//=2
 i+=1
print(i)
N=int(input())
V,H=0,0
for i in range(N):
 if V>H: H+=1
 else: V+=1
 piece=(V+1)*(H+1)
print(piece)
input();R,T=0,0
for i in map(int,input().split()):
 if i:T+=1;R+=T
 else:T=0
print(R)
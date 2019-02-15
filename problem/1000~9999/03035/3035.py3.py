(H,W,ZH,ZW),T=map(int,input().split()),''
for i in range(H):
 for j in input(): T+=j*ZW
 T+='\n'
 for j in range(ZH-1): T+=T.split('\n')[i*ZH]+'\n'
print(T)
import sys
x,r=0,''
for _ in range(int(input())):
 e=sys.stdin.readline()
 o,t=e[1],e.split()[-1]
 if o=='d':x|=1<<int(t)
 if o=='e':x&=~(1<<int(t))
 if o=='h':r+=str(x>>int(t)&1)+'\n'
 if o=='o':x^=1<<int(t)
 if o=='l':x=2097150
 if o=='m':x=0
print(r)
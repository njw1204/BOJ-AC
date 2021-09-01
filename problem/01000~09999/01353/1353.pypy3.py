import sys
s,p=map(int,input().split())
if s==p:
    print(1)
    sys.exit()

asdf=0
for c in range(100,1,-1):
    if s**c>=p*(c**c):
        asdf=c

if asdf:
    print(asdf)
else:
    print(-1)
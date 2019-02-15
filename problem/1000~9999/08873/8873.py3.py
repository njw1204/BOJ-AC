import sys,random
H,W=map(int,input().split())
R,G,B=[],[],[]
for i in range(H):
 for j in map(int,sys.stdin.readline().split()):
  R.append(j)
for i in range(H):
 for j in map(int,sys.stdin.readline().split()):
  G.append(j)
for i in range(H):
 for j in map(int,sys.stdin.readline().split()):
  B.append(j)

RR,GG,BB=sum(R),sum(G),sum(B)
if GG+RR+BB<H*W*230:
 print(3)
 exit()
if GG>(RR+BB)/1.7:
 print(2)
 exit()
if GG+RR+BB>H*W*585:
 print(1)
 exit()
if RR>(GG+BB):
 print(4)
 exit()
print(random.choice((1,2,3,4)))
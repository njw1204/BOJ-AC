for _ in range(int(input())):
 n,m=map(int,input().split())
 x,y,pos,cnt=[],[],0,0
 for n,i in enumerate(map(int,input().split())):
  x.append((n,i))
  y.append(i)
 y.sort()
 maxPrior=y[-1]
 while 1:
  if x[pos][1]==maxPrior:
   cnt+=1
   if x[pos][0]==m:
    print(cnt)
    break
   pos+=1
   y.pop()
   maxPrior=y[-1]
  else:
   x.append((x[pos][0],x[pos][1]))
   pos+=1
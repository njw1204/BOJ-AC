for _ in range(int(input())):
 p,n=input(),int(input())
 x=input()[1:-1].split(',')
 pos,rpos,mode=0,n-1,0
 error=False
 for i in p:
  if i=='R': mode=(mode+1)%2
  else:
   if pos>rpos:
    print('error')
    error=True
    break
   if mode==0: pos+=1
   else: rpos-=1
 if error: continue
 print(end='[')
 if mode==0:
  for i in range(pos,rpos+1):
   print(end=x[i])
   if i!=rpos: print(end=',')
 else:
  for i in range(rpos,pos-1,-1):
   print(end=x[i])
   if i!=pos: print(end=',')
 print(']')
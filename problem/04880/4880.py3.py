while 1:
 x,y,z=map(int,input().split())
 if x==y==z==0: break
 if y-x==z-y:
  print('AP',z+(z-y))
 else:
  print('GP',z*(z//y))
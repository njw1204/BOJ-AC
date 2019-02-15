x=[[0]*15 for i in range(15)]
rCnt,wCnt,i=0,0,0
while 1:
  try:
    t=input()
    wCnt=max(wCnt,len(t))
    for j in range(len(t)):
      x[i][j]=t[j]
    i+=1
    rCnt+=1
  except: break
for i in range(wCnt):
  for j in range(rCnt):
    if x[j][i]==0: continue
    print(x[j][i],end='')
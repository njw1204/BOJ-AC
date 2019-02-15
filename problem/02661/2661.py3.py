def BackTrack(T,remain):
  for i in range(1,4):
    T.append(str(i))
    error=False
    for i in range(1,len(T)//2+1):
      if T[-1:-1-i:-1]==T[-1-i:-1-i*2:-1]:
        error=True
        break
    if not error:
      if remain==1:
        print(''.join(T))
        exit()
      BackTrack(T,remain-1)
    T.pop()

n=int(input())
BackTrack([],n)
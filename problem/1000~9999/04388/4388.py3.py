while 1:
  a,b=input().split()
  if a==b=='0': break
  a,b=list(a),list(b)
  r=0
  c=0
  while a or b:
    if a and b:
      t=c+ord(a[-1])+ord(b[-1])-ord('0')*2
      a.pop()
      b.pop()
    elif a:
      t=c+ord(a[-1])-ord('0')
      a.pop()
    else:
      t=c+ord(b[-1])-ord('0')
      b.pop()
    if t>9:
      c=1
      r+=1
  print(r)
i=0
while 1:
  i+=1
  a,b=input(),input()
  if a==b=='END': break
  a,b=sorted(a),sorted(b)
  if a==b: print('Case %d: same'%i)
  else: print('Case %d: different'%i)
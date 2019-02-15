x,maxc,ans=[0]*128,0,[]
try:
 while 1:
  n=input()
  for i in n:
   if ord(i)>=ord('a') and ord(i)<=ord('z'): x[ord(i)]+=1
except: pass
for i in range(128):
 if x[i]>maxc:
  maxc=x[i]
  ans=[chr(i)]
 elif x[i]==maxc and maxc: ans.append(chr(i))
print(''.join(ans))
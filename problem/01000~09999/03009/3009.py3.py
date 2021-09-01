x,y,s=[],[],[]
exec('a,b=map(int,input().split());x.append(a);y.append(b);'*3+'s.append(x);s.append(y)')

for i in range(2):
 if s[i].count(s[i][0])==1: print(s[i][0],end=' ')
 elif s[i][0]==max(s[i]): print(min(s[i]),end=' ')
 else: print(max(s[i]),end=' ')
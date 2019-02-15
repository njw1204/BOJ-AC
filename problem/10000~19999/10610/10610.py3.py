n=input()
if '0' not in n or sum(map(int,list(n)))%3:
 print(-1)
else:
 print(''.join(sorted(n,reverse=True)))
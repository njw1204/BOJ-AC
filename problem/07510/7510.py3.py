for i in range(1,int(input())+1):
 x=sorted(map(int,input().split()))
 print('Scenario #%d:'%i)
 if x[-1]*x[-1]==x[0]*x[0]+x[1]*x[1]: print('yes\n')
 else: print('no\n')
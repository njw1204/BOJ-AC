for i in range(1,999):
 l,p,n=map(int,input().split())
 if l==0: break
 print('Case ',i,': ',n//p*l+min(n%p,l),sep='')
import sys

def B2C(T):
 ret,digit=0,1
 for i in reversed(T):
  ret+=digit*int(i)
  digit*=2
 return chr(ret)

for _ in range(1,int(input())+1):
 length=int(sys.stdin.readline())
 print('Case #%d: '%_,end='')
 T=sys.stdin.readline().replace('I','1').replace('O','0')
 ans=''
 for i in range(0,length*8,8): ans+=B2C(T[i:i+8])
 print(ans)
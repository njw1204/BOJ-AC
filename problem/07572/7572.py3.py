N=int(input())
val1,val2=0,0
if N>=2008: val1=(N-2008)%12
else: val1=-((2008-N)%12)
if N>=2014: val2=(N-2014)%10
else: val2=-((2014-N)%10)
print('ABCDEFGHIJKL'[val1]+'0123456789'[val2])
num=0
for i in input():
 if i.islower(): num+=ord(i)-ord('a')+1
 else: num+=ord(i)-ord('A')+27

for i in range(2,num//2+1):
 if num%i==0:
  print('It is not a prime word.')
  exit()
print('It is a prime word.')
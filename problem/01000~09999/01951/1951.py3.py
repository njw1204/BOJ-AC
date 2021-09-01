N = int(input())
digit = 0
count = 0
T = N//10

while T>0:
  digit+=1
  count+=digit*9*(10**(digit-1))
  count%=1234567
  T//=10

start_num = 10**digit
count += (digit+1) * (N - start_num + 1)
count %= 1234567
print(count)
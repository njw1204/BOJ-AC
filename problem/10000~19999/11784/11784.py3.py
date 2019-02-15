while 1:
 try:
  for i in map(''.join,zip(*[iter(input()+'0A')]*2)):print(chr(int(i,16)),end='')
 except:break
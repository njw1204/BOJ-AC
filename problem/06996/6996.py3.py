for _ in range(int(input())):
  a,b=input().split()
  cxc=True
  for i in range(ord('a'),ord('z')+1):
    if a.count(chr(i))!=b.count(chr(i)):
      cxc=False
      break
  if cxc: print(a,'&',b,'are anagrams.')
  else: print(a,'&',b,'are NOT anagrams.')
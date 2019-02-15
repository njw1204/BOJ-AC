for i in range(int(input())):
  a=input().split()
  print(int(str(int(a[0][::-1])+int(a[1][::-1]))[::-1]))
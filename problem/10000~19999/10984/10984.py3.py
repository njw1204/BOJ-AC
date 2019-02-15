for _ in range(int(input())):
 ave,cnt=0,0
 for __ in range(int(input())):
  A,B=input().split()
  cnt+=int(A)
  ave+=float(B)*int(A)
 ave/=cnt
 print('%d %.1f'%(cnt,ave))
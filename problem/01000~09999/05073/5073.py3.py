while True:
 A,B,C=map(int,input().split())
 if not A: exit()
 if A+B+C<=max(A,B,C)*2: print('Invalid')
 elif A==B==C: print('Equilateral')
 elif True in (A==B,A==C,B==C): print('Isosceles')
 else: print('Scalene')
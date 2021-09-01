A,B,C,D,E=35034,23090,19055,12530,18090
for _ in range(int(input())):
 a,b,c,d,e=map(int,input().split())
 print('$%.2f'%((A*a+B*b+C*c+D*d+E*e)/100))
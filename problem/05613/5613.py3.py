a=int(input())
m=''
while 1:
 n=input()
 if n=='=': break
 elif n=='+': m='+'
 elif n=='-': m='-'
 elif n=='*': m='*'
 elif n=='/': m='//'
 else: a=eval(str(a)+m+n)
print(a)
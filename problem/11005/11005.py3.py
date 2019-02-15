def ChangeRadix(num,before,after): 
 num=int(str(num),before) 
 result,weight=[],1 
 while num: 
  x=num%after 
  result.append(str(x) if x<10 else chr(ord('A')+x-10)) 
  num//=after 
  weight*=after 
 return ''.join(reversed(result)) if result!=[] else '0'

n,b=map(int,input().split())
print(ChangeRadix(n,10,b))
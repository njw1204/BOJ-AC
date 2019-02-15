for _ in range(int(input())):
 T=input()
 print('%.2f'%eval('('*(T.count('@')+T.count('#')+T.count('%'))+T.replace('@','*3)').replace('%','+5)').replace('#','-7)')))
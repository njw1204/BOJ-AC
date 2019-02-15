for _ in range(int(input())):
 HP,MP,ATK,DEF,DHP,DMP,DATK,DDEF=map(int,input().split())
 HP,MP,ATK,DEF=HP+DHP,MP+DMP,ATK+DATK,DEF+DDEF
 if HP<1: HP=1
 if MP<1: MP=1
 if ATK<0: ATK=0
 print(HP+MP*5+ATK*2+DEF*2)
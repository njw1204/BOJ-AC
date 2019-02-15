for _ in range(int(input())):
 price,money,need,get=map(int,input().split())
 sang=money//price+money//price*get//need
 doo=money//price
 coupon=doo*get
 while coupon>=need:
  t=coupon//need
  coupon%=need
  doo+=t
  coupon+=t*get
 print(doo-sang)
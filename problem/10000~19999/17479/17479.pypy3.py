import sys

input=sys.stdin.readline

normal_dish, special_dish, service_dish = dict(), dict(), set()

all_dish = dict()

all_dish_price = dict()

dish_cnt = [0]*3

dish_price = [0]*2

a,b,c=map(int,input().split())

for i in range(a):

    name,price=input().split()

    price=int(price)

    all_dish[name] = 0

    all_dish_price[name] = price

for i in range(b):

    name,price=input().split()

    price=int(price)

    all_dish[name] = 1

    all_dish_price[name] = price

for i in range(c):

    name=input().strip()

    service_dish.add(name)

    all_dish[name] = 2

for i in range(int(input())):

    name=input().strip()

    if all_dish[name] != 2:

        dish_cnt[all_dish[name]] += 1

        dish_price[all_dish[name]] += all_dish_price[name]

    else:

        dish_cnt[2] += 1

if dish_cnt[2] > 1 or dish_cnt[2] == 1 and sum(dish_price) < 50000:

    print("No")

    exit(0)

if dish_cnt[1] > 0 and dish_price[0] < 20000:

    print("No")

    exit(0)

print("Okay")
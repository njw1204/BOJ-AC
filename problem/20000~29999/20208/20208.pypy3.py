from itertools import permutations

def get_dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

n, m, h = map(int,input().split())
field = []
for i in range(n):
    field.append([*map(int,input().split())])

si = sj = 0
milk_list = []
for i in range(n):
    for j in range(n):
        if field[i][j] == 1:
            si = i
            sj = j
        elif field[i][j] == 2:
            milk_list.append([i, j])

ans = 0
for milk_permutation in permutations(milk_list):
    ni, nj, hp = si, sj, m
    drinked_milk_count = 0
    for i, j in milk_permutation:
        dist = get_dist(ni, nj, i, j)
        new_hp = hp - dist
        if new_hp < 0:
            break

        new_hp += h
        drinked_milk_count += 1
        if get_dist(si, sj, i, j) <= new_hp:
            ans = max(ans, drinked_milk_count)

        ni, nj, hp = i, j, new_hp

print(ans)
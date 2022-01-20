from math import ceil
# purchase-options  number-of-enemies
# health    base-damage
# items-price
# enemies-health
itemsNenemies = input()
A = input()
lst = list(map(int,A.split()))
h = lst[0]
d = lst[1]
A = input()
items = list(map(int,A.split()))
A = input()
enemies = list(map(int,A.split()))
items.sort()
items.reverse()
enemies.reverse()

def run(h,d,items,enemies):
    item = 0
    dc = d
    while (items):
        print(d)
        bla = ceil(enemies/d)
        if (h >= bla):
            if item == 0:
                return "Veski Eyleifs er bjargad"
            return item
        item = items.pop()
        d = dc + item
    return "Nu er Eyleifur i bobba"

print(run(h+len(enemies)-1,d,items,sum(enemies)))

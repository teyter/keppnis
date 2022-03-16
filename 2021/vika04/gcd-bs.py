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

def run(h,d,items,enemies):
    item = 0
    win = fights(h,d+item,enemies.copy())
    if win:
        return "Veski Eyleifs er bjargad"
    last_item = -1
    middle = ceil(len(items)/2)-1
    while len(items) > 0:
        item = items[middle]
        win = fights(h,d+item,enemies.copy())
        if win: 
            last_item = item
            items = items[:middle]
            middle = ceil(len(items)/2)-1
        else:
            items = items[middle+1:]
            middle = ceil(len(items)/2)-1

    if last_item == -1:
        return "Nu er Eyleifur i bobba"
    return last_item

def fights(h,dmg,enemies):
    while (h > 0 and enemies != []):
        h = fight(h,dmg,enemies.pop())
    if (h > 0): return True
    return False

def fight(h,dmg,enemy):
    while (h >= 0 and enemy >= 0):
        enemy -= dmg
        if (enemy <= 0): break
        h -= 1
    return h

print(run(h,d,items,enemies))

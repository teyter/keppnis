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

def run(h,d,items,enemies):
    lower = 0
    upper = len(items)+1
    middle = int(upper/2)
    curr_lowest = 10**9
    while upper > lower:
        ph = h
        pd = d+items[middle]

        win = fights(ph,pd,enemies)

        if win:
            if middle < curr_lowest:
                curr_lowest = middle
            upper = middle
            middle = int(lower+(upper-lower)/2)

        elif not win:
            if middle+1 == curr_lowest:
                break
            lower = middle
            middle = int(upper-(upper-lower)/2)

    if curr_lowest == 10**9:
        return "Nu er Eyleifur i bobba"
    elif curr_lowest == 0:
        return "Veski Eyleifs er bjargad"
    else:
        return items[curr_lowest]


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

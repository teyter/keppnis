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
    ecpy = enemies.copy()
    item = 0
    while (items):
        bla = fights(h,d+item,enemies.copy())
        if (bla):
            if item == 0:
                return "Veski Eyleifs er bjargad"
            else: 
                return item
        item = items.pop()
    return "Nu er Eyleifur i bobba"

def fights(h,dmg,enemies):
    while (h > 0 and enemies != []):
        print()
        h = fight(h,dmg,enemies.pop())
    if (h > 0): return True
    return False

def fight(h,dmg,enemy):
    while (h >= 0 and enemy >= 0):
        print("eyleif",h,"enemy",enemy,"damage",dmg)
        enemy -= dmg
        if (enemy <= 0): break
        h -= 1
    return h




print(run(h,d,items,enemies))

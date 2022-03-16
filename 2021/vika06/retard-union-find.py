A = input()
lst = list(map(int,A.split()))
N = lst[0]
Q = lst[1]
lst = []
for i in range(Q):
    lst.append(input().split())

sett = {}

for i in lst:
    op = i[0]
    a = i[1]
    b = i[2]
    if op == "?":
        if a == b:
            print("yes")
        else:
            try:
                sett[a]
                sett[b]
                print("yes")
            except:
                print("no")
    if op == "=":
        sett.update({a:0})
        sett.update({b:0})

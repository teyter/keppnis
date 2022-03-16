A = input()
lst = list(map(int,A.split()))
N = lst[0]
Q = lst[1]
lst = []
for i in range(Q):
    lst.append(input().split())

sett = set()

for i in lst:
    op = i[0]
    a = i[1]
    b = i[2]
    if op == "?":
        if a == b:
            print("yes")
        elif a in sett and b in sett:
            print("yes")
        else:
            print("no")
    if op == "=":
        sett.add(a)
        sett.add(b)

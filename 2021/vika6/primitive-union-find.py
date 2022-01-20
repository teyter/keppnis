A = input()
lst = list(map(int,A.split()))
N = lst[0]
Q = lst[1]
lst = []
for i in range(Q):
    lst.append(input().split())
p = [i for i in range(N)]

def find(x):
    if p[x] == x: return x
    return find(p[x])

def join(x,y):
    p[find(x)] = find(y)

for i in lst:
    op = i[0]
    a = int(i[1])
    b = int(i[2])
    if op == "?":
        if find(a) == find(b):
            print("yes")
        else:
            print("no")
    if op == "=":
        join(a,b)

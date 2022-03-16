from math import ceil
A = input()
lst = list(map(int,A.split()))
n = lst[0]
w = lst[1]
A = input()
e = list(map(int,A.split()))

summe = sum(e)
h = ceil(summe/w)
res = 0
for i in e:
    r = i % h
    if r != 0:
        r = abs(r-h)
    res+=r

print(res)

from math import ceil
A = input()
lst = list(map(int,A.split()))
n = lst[0]
w = lst[1]
A = input()
e = list(map(int,A.split()))

summe = sum(e)
h = ceil(summe/w)
print("height:",h)
print((w*h)-summe)

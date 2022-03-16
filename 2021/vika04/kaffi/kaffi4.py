from math import ceil
A = input()
lst = list(map(int,A.split()))
n = lst[0]
w = lst[1]
A = input()
e = list(map(int,A.split()))
summe = sum(e)

def bla(e,n):
    ret = 0
    for i in e:
        ret += ceil(i/n)
    return ret

h = n
q = bla(e,h)
while q <= w:
    h-=1
    q = bla(e,h)

h+=1
print((w*h)-summe)
print()
print(summe/3,bla(e,3))

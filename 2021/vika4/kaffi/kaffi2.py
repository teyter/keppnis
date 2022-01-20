from math import ceil
A = input()
lst = list(map(int,A.split()))
n = lst[0]
w = lst[1]
A = input()
e = list(map(int,A.split()))

summe = sum(e)

def bla(lst,n):
    ret = 0
    for i in lst:
        ret += ceil(i/n)
    return ret
i = 1
q = bla(e,i)
while (q > w):
    q = bla(e,i)
    i+=1

i-=1
print((w*i)-summe)

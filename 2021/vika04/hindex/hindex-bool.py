import numpy as np

n = int(input())
lst = np.array([int(input()) for c in range(n)])

def hindex(lst,h):
    mask = lst >= h
    if len(lst[mask]) >= h:
        return h
    return 0

res = hindex(lst,n)
while (res < n):
    res = hindex(lst,n)
    n-=1

print(res)

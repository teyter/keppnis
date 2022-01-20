n = int(input())
lst = [int(input()) for c in range(n)]

def hindex(lst,h):
    ret = []
    for i in lst:
        if i >= h:
            ret.append(i)
    count = len(ret)
    if count >= h:
        return h
    return 0

res = hindex(lst,n)
while (res < n):
    res = hindex(lst,n)
    n-=1

print(res)

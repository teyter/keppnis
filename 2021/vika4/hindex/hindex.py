n = int(input())
lst = [int(input()) for c in range(n)]

def hindex(lst,h):
    if h == 0: return h
    ret = []
    for i in lst:
        if i >= h:
            ret.append(i)
    count = len(ret)
    if count >= h:
        return h
    return hindex(lst,h-1)

res = hindex(lst,n)
print(res)

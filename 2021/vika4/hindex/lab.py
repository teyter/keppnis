n = int(input())
lst = [int(input()) for c in range(n)]
lst.sort()

def hindex(lst,n):
    for i in range(n):
        x = n-i
        if lst[i] >= x:
            return x
    return 0

res = hindex(lst,n)
print(res)

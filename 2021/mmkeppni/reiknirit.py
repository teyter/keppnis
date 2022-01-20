n = int(input())
s = input()
lst = list(map(int,s.split()))
ret = sum([lst.count(i) for i in lst])
print(ret)

def freq(lst):
    ret = []
    for i in lst:
        ret.append(lst.count(i))
    return ret

print(sum(freq(lst)))


from itertools import permutations
x = input()
lst = list(permutations(x))
ret = []
for i in lst:
    y = int("".join(i))
    if y > int(x):
        ret.append(y)

if ret == []:
    print(0)
else:
    print(min(ret))
